#!/bin/sh

# Validate required environment variables
: "${DOMAIN_NAME:?DOMAIN_NAME is required}"
: "${MYSQL_DATABASE:?MYSQL_DATABASE is required}"
: "${MYSQL_USER:?MYSQL_USER is required}"
: "${MYSQL_PASSWORD:?MYSQL_PASSWORD is required}"
: "${MYSQL_HOST:?MYSQL_HOST is required}"
: "${WP_TITLE:?WP_TITLE is required}"
: "${WP_ADMIN_USER:?WP_ADMIN_USER is required}"
: "${WP_ADMIN_PASSWORD:?WP_ADMIN_PASSWORD is required}"
: "${WP_ADMIN_EMAIL:?WP_ADMIN_EMAIL is required}"
: "${WP_USER:?WP_USER is required}"
: "${WP_USER_PASSWORD:?WP_USER_PASSWORD is required}"
: "${WP_USER_EMAIL:?WP_USER_EMAIL is required}"

# Wait for MariaDB to be ready
echo "Waiting for MariaDB..."
until mysqladmin ping -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" --silent 2>/dev/null; do
	sleep 2
done
echo "MariaDB is ready!"

# Download WordPress if not present
if [ ! -f /var/www/html/wp-includes/version.php ]; then
	echo "Downloading WordPress..."
	wp core download --allow-root 2>/dev/null
fi

# Create wp-config.php if not present
if [ ! -f /var/www/html/wp-config.php ]; then
	echo "Creating wp-config.php..."
	wp config create \
		--dbname="$MYSQL_DATABASE" \
		--dbuser="$MYSQL_USER" \
		--dbpass="$MYSQL_PASSWORD" \
		--dbhost="$MYSQL_HOST" \
		--allow-root 2>/dev/null
fi

# Install WordPress if not installed
if ! wp core is-installed --allow-root 2>/dev/null; then
	echo "Installing WordPress..."
	wp core install \
		--url="https://${DOMAIN_NAME}" \
		--title="$WP_TITLE" \
		--admin_user="$WP_ADMIN_USER" \
		--admin_password="$WP_ADMIN_PASSWORD" \
		--admin_email="$WP_ADMIN_EMAIL" \
		--skip-email \
		--allow-root 2>/dev/null

	# Create additional user
	wp user create "$WP_USER" "$WP_USER_EMAIL" \
		--role=author \
		--user_pass="$WP_USER_PASSWORD" \
		--allow-root 2>/dev/null
fi

# Ensure correct permissions
chown -R www:www /var/www/html

# Start php-fpm in foreground (PID 1 best practice)
exec php-fpm82 -F
