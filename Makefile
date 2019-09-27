# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 20:19:49 by nolakim           #+#    #+#              #
#    Updated: 2019/09/27 03:14:30 by nolakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	ft_ls

SRC =	./*.c

OBJ = 	*.o

INC = 	-I ./ft_ls.h \
		-I ./libft/libft.h 
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@make -C ./libft re
	@gcc $(FLAGS) -c -I $(INC) $(SRC)
	@gcc $(FLAGS) $(INC) -L ./libft -lft $(OBJ) -o $(NAME)

clean :
	@rm -fr $(OBJ)
	@find . -type f -name '*.o' -delete
	@find . -type f -name '*.gch' -delete

fclean : clean
	@make -C ./libft/ fclean
	@rm -fr $(NAME)
re :
	@make fclean
	@make all
