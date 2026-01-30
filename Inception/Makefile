build:
	cd src/ && docker-compose -f docker_compose.yml build

up:
	cd src/ && docker-compose -f docker_compose.yml up -d

down:
	cd src/ && docker-compose -f docker_compose.yml down

kill:
	cd src/ && docker system prune -af --volumes ; docker volume prune -af

re:
	cd src/ && docker system prune -af --volumes ; docker volume prune -af && docker-compose -f docker_compose.yml down && docker-compose -f docker_compose.yml up -d

ps:
	cd src/ && docker ps -a

images:
	cd src/ && docker images

.PHONY: build up down kill re ps