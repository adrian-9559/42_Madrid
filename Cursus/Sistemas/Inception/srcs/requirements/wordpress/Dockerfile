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
	&& ln -s /usr/bin/php82 /usr/bin/php \
	&& for ext in mysqlnd mysqli pdo_mysql; do \
		if [ -f /etc/php82/conf.d-available/${ext}.ini ]; then \
			ln -sf /etc/php82/conf.d-available/${ext}.ini /etc/php82/conf.d/${ext}.ini; \
		fi; \
	done

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
