#!/bin/sh

# Create run directory for mysqld socket
mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld

# Initialize database if not already done
if [ ! -d "/var/lib/mysql/mysql" ]; then
	mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null 2>&1

	# Start MariaDB temporarily to run initialization queries
	mysqld --user=mysql --datadir=/var/lib/mysql &
	PID=$!

	# Wait for MariaDB to be ready
	while ! mysqladmin ping --silent 2>/dev/null; do
		sleep 1
	done

	# Create database and users
	mysql -u root <<-EOSQL
		CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
		CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
		GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
		CREATE USER IF NOT EXISTS '${WP_ADMIN_USER}'@'%' IDENTIFIED BY '${WP_ADMIN_PASSWORD}';
		GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${WP_ADMIN_USER}'@'%';
		FLUSH PRIVILEGES;
	EOSQL

	# Stop temporary instance
	kill $PID
	wait $PID
fi

# Start MariaDB in foreground (PID 1 best practice)
exec mysqld --user=mysql --datadir=/var/lib/mysql
