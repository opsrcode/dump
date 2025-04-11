CC:=gcc
CFLAGS:=-Wall -Wextra -Werror -pedantic -ggdb -std=c99 $(shell pkg-config --cflags x11)
CLIBS:=$(shell pkg-config --libs x11)
TARGET:=draw
SRCS:=${TARGET}.c
OBJS:=$(SRCS:.c=.o)

${TARGET} : ${OBJS}
	$(CC) ${CFLAGS} ${SRCS} -o ${TARGET} ${CLIBS}

.PHONY : clean
clean:
	@rm -rf ${TARGET} ${OBJS}
