SRC		= main.c ft_putnbr.c ft_math.c

OBJS	= ${SRC:.c=.o}

NAME	= do-op

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
