#!/bin/bash
set -e

# ============================================================================
# MARIADB SETUP SCRIPT
# Script per configurare MariaDB in un container Docker
# ============================================================================

# Controllo che le variabili d'ambiente siano state fornite
if [ -z "$MYSQL_ROOT_PASSWORD" ] || [ -z "$MYSQL_PASSWORD" ] || [ -z "$MYSQL_DATABASE" ] || [ -z "$MYSQL_USER" ]; then
    echo "Errore: Tutte le variabili d'ambiente devono essere impostate"
    echo "MYSQL_ROOT_PASSWORD, MYSQL_DATABASE, MYSQL_USER, MYSQL_PASSWORD"
    exit 1
fi

echo "=========================================="
echo "Avvio setup di MariaDB..."
echo "=========================================="

# Inizializza MariaDB se non è già inizializzato
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Inizializzazione MariaDB..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    echo "✓ MariaDB inizializzato"
fi

# Avvia MariaDB in background
echo "Avvio MariaDB..."
mysqld --user=mysql --datadir=/var/lib/mysql &
MYSQL_PID=$!

# Attendi che MariaDB sia pronto
echo "Attesa avvio di MariaDB..."
for i in {1..30}; do
    if mysqladmin ping &>/dev/null; then
        echo "✓ MariaDB è pronto"
        break
    fi
    sleep 1
done

# Configura MariaDB
echo "Configurazione database e utente..."
mysql <<-EOF
	-- Imposta la password di root
	ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
	
	-- Crea il database
	CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\`;
	
	-- Crea l'utente e assegna i permessi
	CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
	GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%';
	
	-- Applica le modifiche
	FLUSH PRIVILEGES;
EOF
echo "✓ Database '$MYSQL_DATABASE' e utente '$MYSQL_USER' configurati"

echo "=========================================="
echo "✓ Setup di MariaDB completato!"
echo "=========================================="
echo "Database: $MYSQL_DATABASE"
echo "Utente: $MYSQL_USER"
echo "Host: %"
echo "=========================================="

# Ferma il processo temporaneo e riavvia MariaDB in foreground
kill "$MYSQL_PID"
wait "$MYSQL_PID" 2>/dev/null

echo "Avvio MariaDB in foreground..."
exec mysqld --user=mysql --datadir=/var/lib/mysql