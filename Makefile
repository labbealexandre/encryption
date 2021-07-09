BUILD_DIR := ./build
SRC_DIRS := ./src
INC_DIRS := ./include
OBJECT_DIRS := ./obj
TARGET := ${BUILD_DIR}/main.x

# Find all the C files we want to compile
SRCS := $(shell find $(SRC_DIRS) -name *.c)

# String substitution for every C file.
OBJS := $(SRCS:${SRC_DIRS}/%.c=$(OBJECT_DIRS)/%.o)

CFLAGS := -lgmp -Wall

all: ${OBJS}
	mkdir -p $(dir ${TARGET})
	gcc ${OBJS} -o ${TARGET} $(CFLAGS) -I ${INC_DIRS}

$(OBJECT_DIRS)/%.o: ${SRC_DIRS}/%.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $^ -o $@ -I ${INC_DIRS}

clean:
	rm -r $(BUILD_DIR) ${OBJECT_DIRS}
