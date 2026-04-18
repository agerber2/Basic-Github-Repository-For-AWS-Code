CC = gcc
CFLAGS = -Wall -g
LIBS = `xml2-config --cflags --libs`

TARGET = parser
SRC = XMLTitleGatherer.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -f $(TARGET)
