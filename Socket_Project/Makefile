# Makefile

all:	edge.c server_and.c server_or.c client.c
		gcc -g -Wall -o edge edge.c
		gcc -g -Wall -o server_and server_and.c
		gcc -g -Wall -o server_or server_or.c
		gcc -g -Wall -o client client.c

edge:
	./edge

server_or:
	./server_or

server_and:
	./server_and

.PHONY: edge
.PHONY: server_or
.PHONY: server_and
