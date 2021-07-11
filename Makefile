BUILD_DIR := ./build
SRC_DIRS := ./src
INC_DIRS := ./include
OBJECT_DIRS := ./obj
TARGET := ${BUILD_DIR}/main.x
MAIN := main.c

TEST_DIRS := ./test
TEST_SRC_DIRS := ${TEST_DIRS}/src
TEST_INC_DIRS := ${TEST_DIRS}/include
TEST_OBJECT_DIRS := ./test_obj
TEST_TARGET := ${BUILD_DIR}/test.x
TEST_MAIN := ${TEST_DIRS}/main.c

# Find all the C files we want to compile
SRCS := $(shell find $(SRC_DIRS) -name '*.c')

# String substitution for every C file.
OBJS := $(SRCS:${SRC_DIRS}/%.c=$(OBJECT_DIRS)/%.o)

# Find all the C test files we want to compile
TEST_SRCS := $(shell find $(TEST_SRC_DIRS) -name '*.c')

# String substitution for every C test file.
TEST_OBJS := $(TEST_SRCS:${TEST_SRC_DIRS}/%.c=$(TEST_OBJECT_DIRS)/%.o)


CFLAGS := -lgmp -Wall

echo:
	echo ${SRCS}

all: ${OBJS} ${MAIN}
	mkdir -p $(dir ${TARGET})
	gcc ${OBJS} ${MAIN} -o ${TARGET} $(CFLAGS) -I ${INC_DIRS}

test: ${OBJS} ${TEST_OBJS} ${TEST_MAIN}
	mkdir -p $(dir ${TEST_TARGET})
	gcc ${OBJS} ${TEST_OBJS} ${TEST_MAIN} -o ${TEST_TARGET} $(CFLAGS) -I ${INC_DIRS} -I ${TEST_INC_DIRS}

${OBJECT_DIRS}/%.o: ${SRC_DIRS}/%.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $^ -o $@ -I ${INC_DIRS}

${TEST_OBJECT_DIRS}/%.o: ${TEST_SRC_DIRS}/%.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $^ -o $@ -I ${INC_DIRS} -I ${TEST_INC_DIRS}

clean:
	rm -r ${BUILD_DIR} ${OBJECT_DIRS} ${TEST_OBJECT_DIRS}
