CC := g++
CFLAGS := -std=c++11 -Wall -I. -pthread
DEPS := main.h tetrisblock.h tetrisworld.h
OBJ := main.o tetrisblock.o tetrisworld.o
LIBS = -lncurses

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm *.o