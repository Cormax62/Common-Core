# #!/bin/bash
# set -e

# echo "=========================================="
# echo "Avvio setup di MariaDB..."
# echo "=========================================="

# mkdir -p /var/lib/mysql /var/run/mysqld
# chown -R mysql:mysql /var/lib/mysql /var/run/mysqld

# # Inizializza MariaDB se non è già inizializzato
# # if [ ! -f "/READY" ]; then
# #     echo "Inizializzazione MariaDB..."
# #     mysqld --initialize-insecure --user=mysql --datadir=/var/lib/mysql
# #     echo "✓ MariaDB inizializzato"
# #     touch /READY
# # else
# #     echo "✓ MariaDB già inizializzato"
# # fi

# if [ ! -d /var/lib/mysql/mysql ]; then
#     echo "Inizializzazione MariaDB..."
#     mariadb-install-db --user=mysql --datadir=/var/lib/mysql
#     echo "✓ MariaDB inizializzato"
# else
#     echo "✓ MariaDB già inizializzato"
# fi


# # Avvia MariaDB in background
# echo "Avvio MariaDB..."

# echo "Attesa avvio di MariaDB..."
# i=30
# while [ $i -gt 0 ]; do
#     if mysqladmin ping --silent; then
#         echo "✓ MariaDB è pronto"
#         break
#     fi
#     sleep 1
#     i=$((i-1))
# done

# # Configura MariaDB
# echo "Configurazione database e utente..."

# INIT_FILE="/tmp/init.sql"
# cat << EOSQL > $INIT_FILE
# CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};

# CREATE USER IF NOT EXISTS '${MYSQL_ROOT}'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
# CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';

# GRANT ALL PRIVILEGES ON *.* TO '${MYSQL_ROOT}'@'%' WITH GRANT OPTION;
# GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';

# FLUSH PRIVILEGES;

# EOSQL
# echo "✓ Database '$MYSQL_DATABASE' e utente '$MYSQL_USER' configurati"

# echo "=========================================="
# echo "✓ Setup di MariaDB completato!"
# echo "* Database: $MYSQL_DATABASE"
# echo "=========================================="

# echo "Avvio MariaDB in foreground..."
# exec mysqld --user=mysql --datadir=/var/lib/mysql --init-file="$INIT_FILE" --bind-address=0.0.0.0

#!/bin/bash
set -e

echo "== MariaDB bootstrap =="

mkdir -p /var/lib/mysql /var/run/mysqld
chown -R mysql:mysql /var/lib/mysql /var/run/mysqld

# Configure bind-address for all interfaces
sed -i 's/^bind-address.*/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

# Init DB se vuoto
if [ ! -d /var/lib/mysql/mysql ]; then
    echo "Inizializzazione MariaDB..."
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql
fi

# Prepare initialization SQL
INIT_FILE="/tmp/init.sql"
cat << EOSQL > $INIT_FILE
USE mysql;
DELETE FROM user WHERE User='';
DELETE FROM user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1', '%');
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOSQL

echo "Starting MariaDB with initialization..."
exec mysqld --user=mysql --datadir=/var/lib/mysql --bind-address=0.0.0.0 --init-file="$INIT_FILE"
