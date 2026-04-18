CC = gcc
CFLAGS = -Wall -g

TARGET = parser
SRC = XMLTitleGatherer.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	del $(TARGET).exe
