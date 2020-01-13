CFLAGS = -Wall -Wextra -Werror -pedantic -O3
CC = g++
LBLIBS = -lncurses

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = snake

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)

run: 
	./snake
