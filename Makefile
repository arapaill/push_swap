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
#CFLAGS = -Wall -Wextra -Werror
SRC = 	srcs/errors.c srcs/main.c srcs/utils.c srcs/list.c srcs/stack_init.c srcs/ft_split.c srcs/push_swap.c srcs/operator.c
NAME = Push_swap
LIB = ar rcs

all : $(NAME)

$(NAME):	
			@$(CC) $(CFLAGS) ${SRC} -o $(NAME)
			@echo "\033[32m[✓]\033[0m		[$(NAME) compiled]"

%.o: %.c
			$(CC) $(CFLAGS) -c -o $@ $<

clean:
			@rm -f *.o

fclean:	clean
			@rm -f $(NAME)
			@rm -f a.aout
			
re:			fclean all