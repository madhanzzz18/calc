CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

SRC_DIR = src
OBJ_DIR = obj

TARGET = calc
SRCS := $(shell find $(SRC_DIR) -name "*.c")

OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	@echo "Linking $@"
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)   
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@echo "Cleaning build files..."
	rm -rf $(OBJ_DIR) $(TARGET)


.PHONY: all clean


