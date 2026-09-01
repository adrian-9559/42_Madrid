FROM alpine:3.18

RUN apk update && apk add --no-cache \
	mariadb \
	mariadb-client \
	mariadb-common

COPY conf/my.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["/entrypoint.sh"]
