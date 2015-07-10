SRCS 	= $(wildcard *.cpp)
TARGET 	= $(patsubst %.cpp, %, $(SRCS))

all: $(TARGET)

.cpp:
	g++ -g $< -o $@

clean:
	-rm $(TARGET)
