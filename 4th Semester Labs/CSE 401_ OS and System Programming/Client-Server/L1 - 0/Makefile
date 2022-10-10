#
# Makefile for src
#

BINFILES = client server

all: $(BINFILES)

client: client.c
	gcc -o client client.c

server: server.c
	gcc -o server server.c


clean:
	-rm  $(BINFILES)
