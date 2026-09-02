FROM alpine:3.18

RUN apk update && apk add --no-cache \
	php82 \
	php82-fpm \
	php82-mysqlnd \
	php82-mbstring \
	php82-xml \
	php82-gd \
	php82-zip \
	php82-curl \
	php82-phar \
	php82-opcache \
	mariadb-client \
	curl \
	tar \
	gzip \
	&& ln -s /usr/bin/php82 /usr/bin/php

# Fix PHP extension load order: mysqlnd must load BEFORE mysqli and pdo_mysql
RUN cd /etc/php82/conf.d && \
	for f in *mysqlnd*.ini; do [ -f "$f" ] && mv "$f" "10_${f#*[0-9]_}" 2>/dev/null; done && \
	for f in *mysqli*.ini; do [ -f "$f" ] && mv "$f" "20_${f#*[0-9]_}" 2>/dev/null; done && \
	for f in *pdo_mysql*.ini; do [ -f "$f" ] && mv "$f" "20_${f#*[0-9]_}" 2>/dev/null; done

# Set PHP CLI memory limit to 256M for wp-cli
RUN echo "memory_limit = 256M" > /etc/php82/conf.d/99-memory-limit.ini

# Install WP-CLI
RUN curl -o /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x /usr/local/bin/wp

# Create wordpress directory
RUN mkdir -p /var/www/html

COPY conf/www.conf /etc/php82/php-fpm.d/www.conf
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["/entrypoint.sh"]
