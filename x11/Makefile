CC:=gcc
CFLAGS:=-Wall -Wextra -Werror -pedantic -ggdb $(shell pkg-config --cflags x11)
CLIBS:=$(shell pkg-config --libs x11)
TARGET:=window
SRCS:=window.c
OBJS:=$(SRCS:.c=.o)

${TARGET} : ${OBJS}
	$(CC) ${CFLAGS} ${SRCS} -o ${TARGET} ${CLIBS}

.PHONY : clean
clean:
	@rm -rf ${TARGET} ${OBJS}
