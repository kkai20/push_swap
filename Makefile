NAME			= push_swap
SRCS			= main.c
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror #-g -fsanitize=address

LIBFT_DIR		= ./libft
LIBFT			= ${LIBFT_DIR}/libft.a
OBJS			= $(SRCS:.c=.o)
INCLUDES_DIR	= includes
INCLUDES		= -I./${INCLUDES_DIR}
RM				= rm -f

%.o:	%.c
		$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJS)
		$(NAME) $(OBJS)


all:	$(NAME)

clean:
		$(RM) ${OBJS} ${BONUSOBJS}

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
