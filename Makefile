SHELL = /bin/sh

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(LIBFT_DIR)
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = srcs/init_stack.c\
		srcs/push.c\
		srcs/reverse_rotate.c\
		srcs/rotate.c\
		srcs/swap.c\
		srcs/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJS)
		@$(MAKE) -C $(LIBFT_DIR) clean 

fclean: clean
		@$(RM) $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re