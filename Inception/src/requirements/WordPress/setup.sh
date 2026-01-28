#!/bin/bash
set -e

# ============================================================================
# WORDPRESS SETUP SCRIPT
# Script per configurare WordPress in un container Docker
# ============================================================================

echo "=========================================="
echo "Avvio setup di WordPress..."
echo "=========================================="

# Attendi che MariaDB sia pronto
# echo "Attesa connessione a MariaDB..."
# until mysqladmin ping -h "mariadb" --silent &>/dev/null; do
#     echo "MariaDB non è ancora pronto... Attesa..."
#     sleep 2
# done
# echo "✓ MariaDB è raggiungibile"
sleep 30

# Scarica WordPress se non esiste
if [ ! -f "$WP_PATH/wp-config.php" ]; then
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
        --admin_email="$WP_ADMIN_EMAIL" \\
        --allow-root
    echo "✓ WordPress installato"
else
    echo "✓ WordPress già configurato"
fi

if ! wp user get ${WP_USER} --path=$WP_PATH --allow-root > /dev/null 2>&1; then
    echo "Creazione utente ${WP_USER}..."
    wp user create ${WP_USER} ${WP_EMAIL} \
        --role=author \
        --user_pass=${WP_PASSWORD} \
        --path=$WP_PATH \
        --allow-root
    echo "✓ Utente ${WP_USER} creato."
else
    echo "✓ Utente ${WP_USER} già esistente."
fi

wp option update siteurl "https://$WP_URL" --allow-root
wp option update home "https://$WP_URL" --allow-root

echo "=========================================="
echo "✓ Setup di WordPress completato!"
echo "* Titolo: $WP_TITLE"
echo "=========================================="

# Avvia PHP-FPM
echo "Avvio PHP-FPM..."
exec php-fpm7.4 -F