# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 09:58:10 by marvin            #+#    #+#              #
#    Updated: 2021/04/20 09:58:10 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = 	srcs/ps_utils.c srcs/errors.c srcs/utils.c srcs/list.c\
		srcs/stack_init.c srcs/ft_split.c srcs/push_swap.c\
		srcs/do_ope_rotate.c srcs/find_median.c srcs/resolve_less_5.c srcs/ft_atoi.c\
		srcs/ope_swap.c srcs/ope_push.c srcs/ope_rotate.c srcs/main_utils.c
SRC_BONUS = srcs/checker.c GNL/get_next_line.c GNL/get_next_line_utils.c
NAME = push_swap
BONUS = checker
LIB = ar rcs

all : $(BONUS)

$(NAME):	
			@$(CC) $(CFLAGS) ${SRC} srcs/main.c -o $(NAME)
			@echo "\033[32m[✓]\033[0m		[$(NAME) compiled]"
$(BONUS):	
			@make all
			@$(CC) $(CFLAGS) ${SRC} ${SRC_BONUS} -o $(BONUS)
			@echo "\033[32m[✓]\033[0m		[$(BONUS) compiled]"

%.o: %.c
			$(CC) $(CFLAGS) -c -o $@ $<

clean:
			@rm -f *.o

fclean:	clean
			@rm -f $(NAME)
			@rm -f $(BONUS)
			@rm -f a.aout
			
re:			fclean all