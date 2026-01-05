CC = gcc
CFLAGS = -Wall -g -Iinclude
LDFLAGS = -lm

SRCDIR = src
OPSDIR = src/operations
OBJDIR = obj/src
INCDIR = include

OBJ = $(OBJDIR)/main.o $(OBJDIR)/operations.o
TARGET = calc

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET)

$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/operations.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/operations.o: $(OPSDIR)/operations.c $(INCDIR)/operations.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

