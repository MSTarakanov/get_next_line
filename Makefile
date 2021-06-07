NAME = get_next_line.exe

FLAGS = -Wextra -Werror -Wall

SRCS = get_next_line.c \
	   get_next_line_utils.c \
	   main.c

OBJS = ${SRCS:.c=.o}

HEADERS = get_next_line.h

all: ${NAME}

${NAME}: ${OBJS}
	gcc ${FLAGS} $^ -o ${NAME}

%.o: %.c ${HEADERS}
	gcc -O3 -c -o $@ $<

clean:
	del ${OBJS}

fclean: clean
	del /f ${NAME}

re: fclean all
