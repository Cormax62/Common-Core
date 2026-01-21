FROM debian:bullseye-slim

RUN apt-get update && apt-get install -y php7.2 php7.2-cli \
    php7.2-fpm php7.2-mysql php7.2-json php7.2-opcache \
    php7.2-mbstring php7.2-xml php7.2-gd php7.2-curl && \
    apt-get clean && rm -rf /var/lib/apt/lists/* \
    /var/cache/apt/archives

RUN mkdir -p /run/php

