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

GREEN = \033[0;32m
NC = \033[0m
NAME = push_swap.a
SRCS = srcs/checker.c
FLAGS = -Wall -Werror -Wextra
LIB = ar rcs
CC = @gcc
OBJ         =   $(SRCS:.c=.o)
all: $(NAME)
$(NAME):    $(OBJ)
			@make -C ./libft
			@cp ./libft/libft.a $(NAME)
			@$(LIB) $(NAME) ${OBJ}
clean:
	@make clean -C ./libft
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
re: fclean all

exec:	re
		@gcc ${FLAGS} ${NAME} main.c
		@./a.out