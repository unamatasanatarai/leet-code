IMAGE_NAME = leet-dev
CONTAINER_NAME = leet-container

.PHONY: build rebuild run sh stop destroy

build:
	docker build -t $(IMAGE_NAME) .

rebuild:
	docker build --no-cache -t $(IMAGE_NAME) .

run:
	docker run -d --rm --name $(CONTAINER_NAME) -v $$(pwd):/root/dev -w /root/dev $(IMAGE_NAME) tail -f /dev/null

sh:
	docker exec -it $(CONTAINER_NAME) /bin/bash

stop:
	docker stop $(CONTAINER_NAME)

kknd:
	docker rmi $(IMAGE_NAME)
