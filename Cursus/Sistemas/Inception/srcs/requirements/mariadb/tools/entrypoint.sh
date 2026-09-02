#!/bin/sh
set -e

# Validate required environment variables
: "${MYSQL_DATABASE:?MYSQL_DATABASE is required}"
: "${MYSQL_USER:?MYSQL_USER is required}"
: "${MYSQL_PASSWORD:?MYSQL_PASSWORD is required}"
: "${MYSQL_ROOT_PASSWORD:?MYSQL_ROOT_PASSWORD is required}"

# Create run directory for mysqld socket
mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld

# Initialize database if not already done
if [ ! -d "/var/lib/mysql/mysql" ]; then
	echo "[DB] First run: initializing database..."
	if ! mysql_install_db --user=mysql --datadir=/var/lib/mysql; then
		echo "[DB] ERROR: mysql_install_db failed"
		exit 1
	fi
	echo "[DB] Database initialized"

	# Start MariaDB temporarily to run initialization queries
	echo "[DB] Starting temporary MariaDB for initialization..."
	mysqld --user=mysql --datadir=/var/lib/mysql &
	PID=$!

	# Wait for MariaDB to be ready
	RETRIES=0
	while ! mysqladmin ping --silent 2>/dev/null; do
		RETRIES=$((RETRIES + 1))
		if [ "$RETRIES" -ge 30 ]; then
			echo "[DB] ERROR: Temporary MariaDB not ready after 30 attempts"
			kill $PID 2>/dev/null
			exit 1
		fi
		sleep 1
	done
	echo "[DB] Temporary MariaDB ready"

	# Create database and users
	echo "[DB] Creating database and users..."
	mysql -u root <<-EOSQL
		CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
		CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
		GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
		FLUSH PRIVILEGES;
	EOSQL
	echo "[DB] Database and users created"

	# Set root password
	echo "[DB] Setting root password..."
	mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
	echo "[DB] Root password set"

	# Stop temporary instance
	echo "[DB] Stopping temporary MariaDB..."
	kill $PID
	wait $PID
	echo "[DB] Temporary MariaDB stopped"
else
	echo "[DB] Database already initialized, skipping setup"
fi

# Start MariaDB in foreground (PID 1 best practice)
echo "[DB] Starting MariaDB..."
exec mysqld --user=mysql --datadir=/var/lib/mysql
