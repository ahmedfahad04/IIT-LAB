#
# Makefile for src
#

BINFILES = client server

all: $(BINFILES)

client: client.c
	gcc -o c client.c

server: server.c
	gcc -o s server.c -lpthread


clean:
	-rm  $(BINFILES)
