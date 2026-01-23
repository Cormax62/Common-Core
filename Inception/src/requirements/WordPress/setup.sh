#!/bin/bash
set -e

# ============================================================================
# WORDPRESS SETUP SCRIPT
# Script per configurare WordPress in un container Docker
# ============================================================================

# Controllo che le variabili d'ambiente siano state fornite
if [ -z "$MYSQL_HOST" ] || [ -z "$MYSQL_DATABASE" ] || [ -z "$MYSQL_USER" ] || [ -z "$MYSQL_PASSWORD" ]; then
    echo "Errore: Variabili database non impostate"
    exit 1
fi

if [ -z "$WP_TITLE" ] || [ -z "$WP_ADMIN_USER" ] || [ -z "$WP_ADMIN_PASSWORD" ] || [ -z "$WP_ADMIN_EMAIL" ]; then
    echo "Errore: Variabili WordPress non impostate"
    exit 1
fi

echo "=========================================="
echo "Avvio setup di WordPress..."
echo "=========================================="

# Attendi che MariaDB sia pronto
echo "Attesa connessione a MariaDB..."
until mysqladmin ping -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" &>/dev/null; do
    echo "MariaDB non è ancora pronto... Attesa..."
    sleep 2
done
echo "✓ MariaDB è raggiungibile"

# Imposta la directory di WordPress
WP_DIR="/var/www/html"
cd "$WP_DIR"

# Scarica WordPress se non esiste
if [ ! -f "wp-config.php" ]; then
    echo "Download di WordPress..."
    wp core download --allow-root
    echo "✓ WordPress scaricato"
    
    # Configura WordPress
    echo "Configurazione WordPress..."
    wp config create \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$MYSQL_PASSWORD" \
        --dbhost="$MYSQL_HOST" \
        --allow-root
    echo "✓ File wp-config.php creato"
    
    # Installa WordPress
    echo "Installazione WordPress..."
    wp core install \
        --url="$WP_URL" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --allow-root
    echo "✓ WordPress installato"
else
    echo "✓ WordPress già configurato"
fi

echo "=========================================="
echo "✓ Setup di WordPress completato!"
echo "=========================================="
echo "Titolo: $WP_TITLE"
echo "Admin: $WP_ADMIN_USER"
echo "URL: $WP_URL"
echo "=========================================="

# Avvia PHP-FPM
echo "Avvio PHP-FPM..."
exec php-fpm7.4 -F