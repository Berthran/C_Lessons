all: client

client: client.o server.o
	gcc client.o server.o -o client

clien.o: client.c
	gcc -std=c99 -pedantic -Wall -c client.c

server.o: server.c
	gcc -std=c99 -pedantic -Wall -c server.c

clean:
	rm -f client client.o server.o
