DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_LIB = ../lib
DIR_INC = -I ./include

SRCS = $(wildcard $(DIR_SRC)/*.c)
OBJS = $(patsubst %.c, $(DIR_OBJ)/%.o, $(notdir $(SRCS)))

LIBS = $(DIR_LIB)/libmath.a
AR = ar
CC = g++
CFLAGS = -g

$(LIBS): $(OBJS)
	$(AR) -r $@ $^
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(DIR_INC)

clean:
	rm $(LIBS) $(OBJS)
