.PHONY:clean
CC=gcc
CFLAGS=-Wall -g
BIN=miniftp
OBJS=main.o sysutil.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
