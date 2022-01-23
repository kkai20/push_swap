NAME	=	push_swap
# SRCSDIR	=	./srcs
# SRCS	=	$(SRCSDIR)/main.c
SRCS	=	main.c
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -MMD -MP
OBJS	=	$(SRCS:.c=.o)
DEPENDS	=	$(OBJS:.o=.d)

LIBFT_DIR	= ./libft
LIBFT_A			= $(LIBFT_DIR)/libft.a

%.o:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)
-include $(DEPENDS)

all:	$(NAME)

clean:
			make clean -C $(LIBFT_DIR)
			rm -rf $(OBJS) $(DEPENDS)

fclean:	clean
			make fclean -C $(LIBFT_DIR)
			rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
