#!/bin/bash
set -e

SOCKET="/run/mysqld/mysqld.sock"
mkdir -p /run/mysqld
chown -R mysql:mysql /var/lib/mysql /run/mysqld
chmod 777 /run/mysqld

if [ ! -f "/var/lib/mysql/.bootstrap_done" ]; then
    echo "Inizializzazione MariaDB..."
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql
    FIRST_RUN=1
else
    echo "✓ MariaDB già inizializzato"
    FIRST_RUN=0
fi

# Avvia MariaDB in background per la configurazione iniziale
mysqld_safe --user=mysql --datadir=/var/lib/mysql --socket=$SOCKET &
MYSQL_PID="$!"

# Attesa attiva: molto meglio di sleep 21
echo "Attesa avvio socket..."
for i in {30..0}; do
    if mysqladmin -u root --socket=$SOCKET ping --silent; then
        break
    fi
    sleep 1
done

if [ "$i" = 0 ]; then
    echo "Errore: MariaDB non risponde sul socket."
    exit 1
fi

# Configurazione (usiamo sempre il --socket per evitare problemi di rete/hostname)
echo "Configurazione database..."
mysql -u root --socket=$SOCKET <<EOSQL
    CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
    ALTER USER 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
    GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;
    
    CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
    CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
    ALTER USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
    GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
    FLUSH PRIVILEGES;
EOSQL

touch /var/lib/mysql/.bootstrap_done

echo "Spegnimento temporaneo per riavvio in foreground..."
mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" --socket=$SOCKET shutdown
wait "$MYSQL_PID"

echo "Avvio MariaDB definitivo..."
exec mysqld --user=mysql --datadir=/var/lib/mysql --socket=$SOCKET