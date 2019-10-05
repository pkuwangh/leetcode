CC=g++
CFLAGS=-Wall -g -std=c++11
LDFLAGS=-pthread

all: $(TARGET).exe

$(TARGET).exe: $(TARGET).cc
	$(CC) $(CFLAGS) $(TARGET).cc -o $(TARGET).exe $(LDFLAGS)

clean:
	rm -f $(TARGET).exe
