#score/Makefile

DIR_SRC = ./src
DIR_OBJ = ./obj
SUB_DIR = ./math
TARGET = ./bin/main
DIR_INC = -I ./include -I ./math/include
LIBS = ./lib/libmath.a

SRCS = $(wildcard $(DIR_SRC)/*.c)
OBJS = $(patsubst %.c, $(DIR_OBJ)/%.o, $(notdir $(SRCS)))
CC = g++
CFLAGS = -g
MAKE = make
CLEAN = make clean

all: subdir $(TARGET)

subdir: 
	cd $(SUB_DIR) && $(MAKE)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(DIR_INC)

clean:
	cd $(SUB_DIR) && $(CLEAN)
	rm $(TARGET) $(OBJS)

