FROM alpine:3.18

ARG DOMAIN_NAME=localhost

RUN apk update && apk add --no-cache \
	nginx \
	openssl \
	envsubst

# Generate self-signed SSL certificate
RUN mkdir -p /etc/nginx/ssl && \
	openssl req -x509 -nodes -days 365 \
	-subj "/C=ES/ST=Madrid/L=Madrid/O=42/CN=${DOMAIN_NAME}" \
	-newkey rsa:2048 \
	-keyout /etc/nginx/ssl/inception.key \
	-out /etc/nginx/ssl/inception.crt

RUN mkdir -p /var/log/nginx /var/www/html

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 443

ENTRYPOINT ["/entrypoint.sh"]
