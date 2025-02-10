# Amanda Taylor 

CC = g++
CFLAGS = -Wall -Wextra -std=c++11
TARGET = first_fit

all: $(TARGET)

$(TARGET): first_fit.cpp
	$(CC) $(CFLAGS) -o $(TARGET) first_fit.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
