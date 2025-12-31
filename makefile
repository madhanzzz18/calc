CC = gcc
FLAGS = -Wall -Wextra -g -Iinclude

SRC_DIR = src
OBJ_DIR = obj

TARGET = calc
SRCS := $(shell find $(SRC_DIR) -name "*.c")

OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)   
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning build files..."
	rm -rf $(OBJ_DIR) $(TARGET)


.PHONY: all clean


