#!/bin/bash
set -e

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

# Scarica WordPress se non esiste
if [ ! -f "$WP_PATH/wp-config.php" ]; then
    echo "Download di WordPress..."
    wp core download --allow-root
    echo "✓ WordPress scaricato"
    
    # Configura WordPress
    echo "Configurazione WordPress..."
    wp config create \
        --dbname="$WP_DB_DATABASE" \
        --dbuser="$WP_DB_USER" \
        --dbpass="$WP_DB_PASSWORD" \
        --dbhost="mariadb" \
        --allow-root
    echo "✓ File wp-config.php creato"

#     sed -i '/Add any custom values between this line and the "stop editing" line./r /dev/stdin' /var/www/html/wp-config.php <<'EOF'
#     define('FORCE_SSL_ADMIN', true);
#     $_SERVER['HTTPS'] = 'on';
# EOF

    # Installa WordPress
    echo "Installazione WordPress..."
    wp core install \
        --url="$WP_URL" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --allow-root --skip-email
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