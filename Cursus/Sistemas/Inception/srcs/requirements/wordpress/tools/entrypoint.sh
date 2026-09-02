#!/bin/sh
set -e

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
echo "[WP] Waiting for MariaDB at ${MYSQL_HOST}..."
RETRIES=0
until mysqladmin ping -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" --silent 2>/dev/null; do
	RETRIES=$((RETRIES + 1))
	if [ "$RETRIES" -ge 30 ]; then
		echo "[WP] ERROR: MariaDB not ready after 30 attempts"
		exit 1
	fi
	echo "[WP] MariaDB not ready yet (attempt $RETRIES/30)..."
	sleep 2
done
echo "[WP] MariaDB is ready!"

# Download WordPress if not present
if [ ! -f /var/www/html/wp-includes/version.php ]; then
	echo "[WP] Downloading WordPress..."
	if ! wp core download --allow-root; then
		echo "[WP] ERROR: Failed to download WordPress"
		exit 1
	fi
	echo "[WP] WordPress downloaded successfully"
else
	echo "[WP] WordPress already downloaded"
fi

# Create wp-config.php if not present
if [ ! -f /var/www/html/wp-config.php ]; then
	echo "[WP] Creating wp-config.php..."
	if ! wp config create \
		--dbname="$MYSQL_DATABASE" \
		--dbuser="$MYSQL_USER" \
		--dbpass="$MYSQL_PASSWORD" \
		--dbhost="$MYSQL_HOST" \
		--allow-root; then
		echo "[WP] ERROR: Failed to create wp-config.php"
		exit 1
	fi
	echo "[WP] wp-config.php created"
else
	echo "[WP] wp-config.php already exists"
fi

# Install WordPress if not installed
if ! wp core is-installed --allow-root 2>/dev/null; then
	echo "[WP] Installing WordPress..."
	if ! wp core install \
		--url="https://${DOMAIN_NAME}" \
		--title="$WP_TITLE" \
		--admin_user="$WP_ADMIN_USER" \
		--admin_password="$WP_ADMIN_PASSWORD" \
		--admin_email="$WP_ADMIN_EMAIL" \
		--skip-email \
		--allow-root; then
		echo "[WP] ERROR: Failed to install WordPress"
		exit 1
	fi
	echo "[WP] WordPress installed"

	# Create additional user
	echo "[WP] Creating additional user: ${WP_USER}"
	if ! wp user create "$WP_USER" "$WP_USER_EMAIL" \
		--role=author \
		--user_pass="$WP_USER_PASSWORD" \
		--allow-root; then
		echo "[WP] ERROR: Failed to create user ${WP_USER}"
		exit 1
	fi
	echo "[WP] User ${WP_USER} created"
else
	echo "[WP] WordPress already installed"
fi

# Ensure correct permissions
echo "[WP] Setting permissions..."
chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html
echo "[WP] Permissions set"

# Start php-fpm in foreground (PID 1 best practice)
echo "[WP] Starting php-fpm..."
exec php-fpm82 -F
