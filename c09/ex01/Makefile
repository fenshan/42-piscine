SRC_DIR	= srcs/

H_DIR	= includes

SRCS 	= ${SRC_DIR}ft_putchar.c ${SRC_DIR}ft_swap.c ${SRC_DIR}ft_putstr.c ${SRC_DIR}ft_strlen.c ${SRC_DIR}ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I ${H_DIR} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
