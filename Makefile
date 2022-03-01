

PROJECT=IPK2021

CC = g++
CFLAGS= -Wall -Wextra -pedantic
FILES=$(wildcard *.cpp)

all: IPK2021


IPK2021:
	$(CC) $(CFLAGS) $(FILES) -o hinfosvc

test:
	./hinfosvc test.txt

clean:
	rm -f hinfosvc
