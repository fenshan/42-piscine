SRCS	= main.c parse.c parse_file.c parse_line.c memory.c number_name.c math.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC		= cc
RM		= rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean
