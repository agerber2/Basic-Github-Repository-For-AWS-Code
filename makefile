CC = gcc
CFLAGS = -Wall -g
LIBS =

TARGET = parser
SRC = XMLTitleGatherer.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
