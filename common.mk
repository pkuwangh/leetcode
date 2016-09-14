CC=g++
CFLAGS=-Wall -g -std=c++11
LDFALGS=

all: $(TARGET).exe

$(TARGET).exe: $(TARGET).cc
	$(CC) $(CFLAGS) $(TARGET).cc -o $(TARGET).exe

clean:
	rm -f $(TARGET).exe
