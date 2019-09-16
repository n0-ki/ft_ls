# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:05:31 by nolakim           #+#    #+#              #
#    Updated: 2019/09/16 01:51:37 by nolakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= ./*.c

INCLUDES = libft.h

OBJECTS = *.o

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(INCLUDES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	
all: $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all