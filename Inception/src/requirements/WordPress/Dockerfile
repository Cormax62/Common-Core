FROM debian:bullseye-slim

RUN apt-get update \
    && apt-get install -y wget curl mariadb-client \
    && apt-get install -y php php-fpm php-mysql php-cli php-curl \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/html

RUN sed -i 's|listen = .*|listen = 9000|' /etc/php/7.4/fpm/pool.d/www.conf

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp \
    && wp cli update

RUN mkdir -p /var/run/php

EXPOSE 9000

COPY ./setup.sh /setup.sh

RUN chmod +x /setup.sh

WORKDIR /var/www/html

CMD ["sh", "/setup.sh"]