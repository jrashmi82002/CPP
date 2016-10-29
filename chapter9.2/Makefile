CC=g++
CFLAGS=-Wall -std=c++11
SOURCES=$(wildcard *.cpp)
EXECUTABLE=program

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm $(EXECUTABLE) 2> /dev/null || true

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)
