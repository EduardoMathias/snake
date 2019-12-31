CFLAGS = -Wall -Wextra -Werror -pedantic -O3
CC = g++-9
LBLIBS = -lncurses

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.c=.o)
EXEC = snake

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)

run: 
	./snake