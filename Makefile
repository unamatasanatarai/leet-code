IMAGE_NAME = leet-dev
CONTAINER_NAME = leet-container

.PHONY: docker-build docker-run docker-sh docker-stop docker-destroy

docker-build:
	docker build -t $(IMAGE_NAME) .

docker-run: docker-build
	docker run -d --rm --name $(CONTAINER_NAME) -v $$(pwd):/home/dev -w /home/dev $(IMAGE_NAME) tail -f /dev/null

docker-sh:
	docker exec -it $(CONTAINER_NAME) /bin/sh

docker-stop:
	docker stop $(CONTAINER_NAME)

docker-destroy:
	docker rmi $(IMAGE_NAME)
