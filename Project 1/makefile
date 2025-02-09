CC = g++
CFLAGS = -Wall -Wextra -std=c++11

all: memory_manager

memory_manager: main.o memory_manager.o
	$(CC) $(CFLAGS) main.o memory_manager.o -o memory_manager

main.o: main.cpp memory_manager.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

memory_manager.o: memory_manager.cpp memory_manager.h
	$(CC) $(CFLAGS) -c memory_manager.cpp -o memory_manager.o

clean:
	rm -f *.o memory_manager
