all:
	@docker compose -f srcs/docker-compose.yml up --build -d

up:
	@docker compose -f srcs/docker-compose.yml up -d

down:
	@docker compose -f srcs/docker-compose.yml down

stop:
	@docker compose -f srcs/docker-compose.yml stop

logs:
	@docker compose -f srcs/docker-compose.yml logs

ps:
	@docker compose -f srcs/docker-compose.yml ps

clean: down
	@docker system prune -f
	@docker volume prune -f

fclean: clean
	@docker compose -f srcs/docker-compose.yml down -v --remove-orphans || true

re: fclean all

.PHONY: all up down stop logs ps clean fclean re
