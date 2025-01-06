SHELL = /bin/sh

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(LIBFT_DIR)
AR = ar rcs
RM = rm -f
ECHO = echo

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = srcs/main.c\
		srcs/utils.c\
		srcs/check.c\
		srcs/parsing.c\
		srcs/operation/swap.c\
		srcs/operation/push.c\
		srcs/operation/rotate.c\
		srcs/operation/reverse_rotate.c

OBJS = $(SRCS:.c=.o)
TOTAL_OBJS := $(words $(OBJS))
CURRENT := 0

# Couleurs
DEF_COLOR	=	\033[0m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
WHITE		=	\033[0;97m
PURPLE		=	\033[0;95m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) || { $(ECHO) "$(RED)Error: Compilation failed!$(DEF_COLOR)"; exit 1; }

%.o: %.c
	$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	@printf "\r\033[K$(BLUE) Libft $(DEF_COLOR) $(WHITE)Progress: [%d/%d] %d%% $(DEF_COLOR) > $(YELLOW)Compiling: %s$(DEF_COLOR)" $(CURRENT) $(TOTAL_OBJS) $$(($(CURRENT)*100/$(TOTAL_OBJS))) $<
	@$(CC) $(CFLAGS) -c $< -o $@ || { $(ECHO) "$(RED)Error: Compilation failed for $<!$(DEF_COLOR)"; exit 1; }
	@sleep 0.00001

$(LIBFT):
	@printf "\r\033[K$(BLUE) push_swap $(DEF_COLOR) $(WHITE)Progress: [%d/%d] 100%% $(DEF_COLOR) > $(GREEN)Compilation completed$(DEF_COLOR)\n" $(TOTAL_OBJS) $(TOTAL_OBJS)
	@$(ECHO) "$(PURPLE)Entering directory: $(LIBFT_DIR)$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS)
	@$(ECHO) "$(BLUE)cleaning push_swap!$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) "$(BLUE)Full clean completed!$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
