NAME			= push_swap
SRCS			= $(wildcard *.c)
OBJS			= $(SRCS:.c=.o)
CC				= gcc
CFLAGS			= #-Wall -Wextra -Werror #-g -fsanitize=address

LIBFT_DIR		= ./libft
LIBFT			= ${LIBFT_DIR}/libft.a
INCLUDES_DIR	= includes
INCLUDES		= -I./${INCLUDES_DIR}
RM				= rm -f

%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		make -C ./libft
		${CC} ${CFLAGS} ${OBJS} $(LIBFT) -o ${NAME}


all:	$(NAME)

clean:
		$(RM) ${OBJS} ${BONUSOBJS}

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
