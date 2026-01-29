FROM debian:bullseye-slim

RUN apt-get update \
    && apt-get install -y mariadb-server mariadb-client \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

COPY ./setup.sh /setup.sh
RUN chmod +x /setup.sh

EXPOSE 3306

ENTRYPOINT ["sh", "/setup.sh"]
CMD ["mysqld"]