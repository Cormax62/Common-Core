FROM debian:bullseye-slim

RUN apt-get update \
    && apt-get install -y mariadb-server \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

COPY ./setup.sh /setup.sh
RUN chmod +x /setup.sh

ENTRYPOINT ["sh", "/setup.sh"]
CMD ["mysqld"]