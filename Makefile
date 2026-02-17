CC = gcc

CFLAGS = -Wall -Wextra -g

TARGET = program

SRCS = Main.c List.c Analysis.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)


clean:
	rm -f $(TARGET)
