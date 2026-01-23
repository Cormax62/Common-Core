FROM debian:bullseye-slim

RUN apt-get update && apt-get install -y \
    mariadb-server && apt-get clean && rm -rf \
    /var/lib/apt/lists/* /var/cache/apt/archives

COPY ./setup.sh /setup.sh

RUN chmod +x /setup.sh

# EXPOSE 3306

CMD ["sh", "/setup.sh"]