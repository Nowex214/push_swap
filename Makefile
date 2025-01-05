SHELL = /bin/sh

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(LIBFT_DIR)
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = srcs/main.c\
		srcs/utils.c\
		srcs/parsing.c\
		srcs/check.c\
		srcs/operation/push.c\
		srcs/operation/reverse_rotate.c\
		srcs/operation/rotate.c\
		srcs/operation/swap.c

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