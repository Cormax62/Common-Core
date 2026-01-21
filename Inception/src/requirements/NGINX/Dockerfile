FROM debian:bullseye-slim

RUN apt-get update && apt-get install -y nginx openssl && apt-get clean && rm -rf /var/lib/apt/lists/* /var/cache/apt/archives

COPY ./default.conf /etc/nginx/conf.d/default.conf

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -newkey rsa:4096 -keyout /etc/nginx/ssl/private.key \
    -out /etc/nginx/ssl/certificate.crt -days 365 -nodes -subj \
    "/C=IT/ST=Tuscany/L=Florence/O=42/CN=mbiagi.42.fr"

CMD ["nginx", "-g", "daemon off;"]