# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:05:31 by nolakim           #+#    #+#              #
#    Updated: 2019/03/17 20:57:24 by nolakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= ./ft_atoi.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c \
			./ft_isprint.c ./ft_memset.c ./ft_strcmp.c ./ft_strcpy.c ./ft_strdup.c \
			./ft_strlen.c ./ft_strncmp.c ./ft_strncpy.c ./ft_strnequ.c ./ft_wrdcnt.c\
			./ft_strstr.c ./ft_toupper.c ./ft_tolower.c ./ft_bzero.c ./ft_memcpy.c \
			./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memmove.c \
			./ft_strcat.c ./ft_strchr.c ./ft_strlcat.c ./ft_strncat.c \
			./ft_strncmp.c ./ft_strncpy.c ./ft_strnstr.c ./ft_strrchr.c ./ft_putchar.c\
			./ft_memalloc.c ./ft_memdel.c ./ft_strnew.c ./ft_strdel.c ./ft_strclr.c \
			./ft_striter.c ./ft_striteri.c ./ft_strmap.c ./ft_strmapi.c ./ft_strequ.c \
			./ft_strsub.c ./ft_strjoin.c ./ft_strtrim.c ./ft_strsplit.c ./ft_itoa.c \
			./ft_putstr.c ./ft_putendl.c ./ft_putnbr.c ./ft_putchar_fd.c ./ft_isspace.c \
			./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_iswspace.c ./ft_intlen.c \
			./ft_lstadd.c ./ft_lstdel.c ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstnew.c ./ft_lstmap.c ./get_next_line.c
				
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