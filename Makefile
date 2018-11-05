# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knaumov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 15:18:06 by knaumov           #+#    #+#              #
#    Updated: 2018/11/05 15:18:07 by knaumov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES_C = -I includes/checker.h
INCLUDES_P = -I includes/push_swap.h
SRCS_C = ./srcs/checker/*
SRCS_P = ./srcs/push_swap/*
UTILS = ./utils/*
NAME = libft_ls.a
EXEC_C = checker
EXEC_P = push_swap
LIBFT = libft/libft.a

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m

$(NAME):
	@echo "$(GREEN)Making objects files for $(NAME)$(RESET)"
	@gcc -Wall -Wextra -Werror $(SRCS) $(UTILS) $(INCLUDES) -c
	@echo "$(GREEN)Compiling $(NAME)$(RESET)"
	@make -C libft
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@echo "$(GREEN)Compiling executable $(EXEC)$(RESET)"
	@gcc -Wall -Wextra -Werror $(NAME) $(LIBFT) $(INCLUDES) main.c -o $(EXEC)
	@echo "$(BLUE)$(NAME): Complete$(RESET)"

all: $(NAME)

clean:
	@echo "$(RED)Deleting objects for $(NAME)$(RESET)"
	@/bin/rm -f *.o
	@make -C libft clean
	@echo "$(BLUE)clean: Complete$(RESET)"

fclean: clean
	@echo "$(RED)Deleting $(NAME)$(RESET)"
	@/bin/rm -f $(NAME)
	@echo "$(RED)Deleting executable $(EXEC)$(RESET)"
	@/bin/rm -f $(EXEC)
	@make -C libft fclean
	@echo "$(BLUE)fclean: Complete$(RESET)"

re: fclean all

leaks: fclean
	gcc -g ./srcs/*.c ./utils/*.c -I includes $(LIBFT)  main.c -o $(EXEC)