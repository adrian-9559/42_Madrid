# Developer Documentation - Inception

## Prerequisites

- Docker 20.10+
- Docker Compose v2+
- Virtual Machine (required by 42 subject)
- make (optional, for Makefile)

## Project Structure

```
Inception/
├── Makefile                    # Build and management commands
├── README.md                   # Project documentation
├── USER_DOC.md                 # End-user documentation
├── DEV_DOC.md                  # Developer documentation (this file)
├── .gitignore                  # Git ignore rules
├── secrets/                    # Credentials (NOT committed to Git)
│   ├── credentials.txt         # DB user and name
│   ├── db_password.txt         # DB user password
│   └── db_root_password.txt    # DB root password
└── srcs/
    ├── .env                    # Environment variables
    ├── docker-compose.yml      # Service definitions
    └── requirements/
        ├── nginx/
        │   ├── Dockerfile      # NGINX image definition
        │   ├── .dockerignore   # Docker build exclusions
        │   ├── conf/
        │   │   └── nginx.conf  # NGINX configuration
        │   └── tools/
        │       └── entrypoint.sh
        ├── wordpress/
        │   ├── Dockerfile      # WordPress image definition
        │   ├── .dockerignore
        │   ├── conf/
        │   │   └── www.conf    # php-fpm configuration
        │   └── tools/
        │       └── entrypoint.sh
        └── mariadb/
            ├── Dockerfile      # MariaDB image definition
            ├── .dockerignore
            ├── conf/
            │   └── my.cnf      # MariaDB configuration
            └── tools/
                └── entrypoint.sh
```

## Environment Setup

### 1. Configure Host DNS

Add to `/etc/hosts`:
```
127.0.0.1 adriescr.42.fr
```

### 2. Create Data Directories

```bash
mkdir -p /home/adriescr/data/wordpress
mkdir -p /home/adriescr/data/db
```

### 3. Generate Secrets

```bash
# Generate random passwords
openssl rand -hex 16 > secrets/db_password.txt
openssl rand -hex 16 > secrets/db_root_password.txt

# Create credentials file
echo "DB_USER=adrian_wp" > secrets/credentials.txt
echo "DB_NAME=wordpress" >> secrets/credentials.txt
```

### 4. Configure Environment Variables

Edit `srcs/.env` with your values:
```bash
DOMAIN_NAME=adriescr.42.fr
MYSQL_DATABASE=wordpress
MYSQL_USER=adrian_wp
MYSQL_PASSWORD=<your_password>
MYSQL_ROOT_PASSWORD=<your_root_password>
WP_TITLE=Inception
WP_ADMIN_USER=adrian_admin
WP_ADMIN_PASSWORD=<your_admin_password>
WP_ADMIN_EMAIL=adrian@42.fr
```

## Building and Running

### Build All Images

```bash
docker compose -f srcs/docker-compose.yml build
```

### Start Services

```bash
docker compose -f srcs/docker-compose.yml up -d
```

### Using Makefile

```bash
make          # Build and start
make up       # Start only
make down     # Stop all
make logs     # View logs
make ps       # List containers
make clean    # Stop and prune
make fclean   # Full cleanup
make re       # Full rebuild
```

## Docker Configuration

### Network

- Name: `inception`
- Driver: `bridge`
- All containers connect to this network

### Volumes

| Volume | Type | Host Path | Container Path |
|--------|------|-----------|----------------|
| `wordpress_data` | named | `/home/adriescr/data/wordpress` | `/var/www/html` |
| `db_data` | named | `/home/adriescr/data/db` | `/var/lib/mysql` |

### Ports

| Service | Container Port | Host Port |
|---------|---------------|-----------|
| nginx | 443 | 443 |
| wordpress | 9000 | internal only |
| mariadb | 3306 | internal only |

## Service Details

### NGINX

- **Base**: Alpine 3.18 + nginx
- **SSL**: Self-signed certificate (TLSv1.2/1.3 only)
- **Config**: `/etc/nginx/nginx.conf`
- **Logs**: `/var/log/nginx/`
- **Role**: Reverse proxy, serves static files, forwards PHP to WordPress

### WordPress

- **Base**: Alpine 3.18 + php82-fpm
- **WP-CLI**: Installed for WordPress management
- **Config**: `/etc/php82/php-fpm.d/www.conf`
- **Port**: 9000 (FastCGI)
- **Role**: CMS application, handles PHP processing

### MariaDB

- **Base**: Alpine 3.18 + mariadb
- **Config**: `/etc/my.cnf.d/mariadb-server.cnf`
- **Port**: 3306
- **Role**: Database storage

## Common Commands

### Container Management

```bash
# Enter container shell
docker exec -it nginx sh
docker exec -it wordpress sh
docker exec -it mariadb sh

# View container processes
docker top nginx
docker top wordpress
docker top mariadb

# Inspect container
docker inspect nginx
```

### Database Operations

```bash
# Access MariaDB CLI
docker exec -it mariadb mysql -u root -p

# Backup database
docker exec mariadb mysqldump -u root -p wordpress > backup.sql

# Restore database
docker exec -i mariadb mysql -u root -p wordpress < backup.sql
```

### WordPress Management

```bash
# WP-CLI commands
docker exec -it wordpress wp --allow-root core version
docker exec -it wordpress wp --allow-root plugin list
docker exec -it wordpress wp --allow-root user list
```

### Logs and Debugging

```bash
# Follow all logs
docker compose -f srcs/docker-compose.yml logs -f

# Specific service logs
docker logs -f nginx
docker logs -f wordpress
docker logs -f mariadb

# Check container health
docker inspect --format='{{.State.Status}}' nginx
```

## Troubleshooting

### Build Failures

```bash
# Clean build cache
docker system prune -a

# Rebuild without cache
docker compose -f srcs/docker-compose.yml build --no-cache
```

### Port Conflicts

```bash
# Check what's using port 443
lsof -i :443

# Stop conflicting service
sudo lsof -ti :443 | xargs kill -9
```

### Permission Issues

```bash
# Fix data directory permissions
sudo chown -R $USER:$USER /home/adriescr/data
```

### Network Issues

```bash
# Inspect network
docker network inspect inception

# Test connectivity between containers
docker exec nginx ping wordpress
docker exec wordpress ping mariadb
```

## Adding a New Service

1. Create directory: `srcs/requirements/<service>/`
2. Add `Dockerfile`
3. Add configuration files in `conf/`
4. Add `entrypoint.sh` in `tools/`
5. Add `.dockerignore`
6. Add service to `docker-compose.yml`
7. Rebuild: `docker compose -f srcs/docker-compose.yml build`
