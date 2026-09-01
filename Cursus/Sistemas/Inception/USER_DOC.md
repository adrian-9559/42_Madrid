# User Documentation - Inception

## Overview

This project provides a complete web infrastructure with three services:
- **NGINX**: Web server handling HTTPS traffic
- **WordPress**: Website content management system
- **MariaDB**: Database storing all WordPress data

## Getting Started

### Start the Infrastructure

```bash
make
```

This will:
1. Create data directories at `/home/adriescr/data/`
2. Build all Docker images
3. Start all containers

### Stop the Infrastructure

```bash
make down
```

## Accessing Services

### Website

Open your browser and go to:
```
https://adriescr.42.fr
```

**Note**: You may need to accept the self-signed SSL certificate warning.

### WordPress Admin Panel

Go to:
```
https://adriescr.42.fr/wp-admin
```

Login with:
- **Username**: Check `srcs/.env` (WP_ADMIN_USER)
- **Password**: Check `srcs/.env` (WP_ADMIN_PASSWORD)

## Credentials Management

All credentials are stored in two locations:

### Environment Variables (srcs/.env)

Contains:
- `DOMAIN_NAME`: Website domain
- `MYSQL_DATABASE`: Database name
- `MYSQL_USER`: Database username
- `MYSQL_PASSWORD`: Database password
- `MYSQL_ROOT_PASSWORD`: Database root password
- WordPress admin and user credentials

### Docker Secrets (secrets/)

Contains sensitive files:
- `credentials.txt`: Database user and name
- `db_password.txt`: Database user password
- `db_root_password.txt`: Database root password

**IMPORTANT**: Never commit these files to Git. They are automatically excluded via `.gitignore`.

## Checking Service Status

```bash
# List running containers
make ps

# View real-time logs
make logs

# Check specific service logs
docker logs nginx
docker logs wordpress
docker logs mariadb
```

## Troubleshooting

### Services not starting

1. Check if Docker is running:
   ```bash
   docker info
   ```

2. Check container status:
   ```bash
   docker ps -a
   ```

3. View container logs:
   ```bash
   docker logs <container_name>
   ```

### Can't access website

1. Verify DNS resolution:
   ```bash
   ping adriescr.42.fr
   ```

2. Check if NGINX is running:
   ```bash
   docker ps | grep nginx
   ```

3. Verify port 443 is open:
   ```bash
   curl -k https://adriescr.42.fr
   ```

### Database connection issues

1. Check MariaDB is running:
   ```bash
   docker logs mariadb
   ```

2. Verify database was created:
   ```bash
   docker exec -it mariadb mysql -u root -p -e "SHOW DATABASES;"
   ```

## Data Persistence

All data is stored in:
- `/home/adriescr/data/wordpress/` - WordPress files
- `/home/adriescr/data/db/` - MariaDB data

To completely reset the infrastructure:
```bash
make fclean  # Removes all data
make         # Rebuild from scratch
```
