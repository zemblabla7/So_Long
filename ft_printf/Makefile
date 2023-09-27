# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 14:42:11 by casomarr          #+#    #+#              #
#    Updated: 2023/03/21 12:59:15 by casomarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf.c 	\
		is_char.c		\
		is_num_int.c	\
		is_num_u.c		\
		is_pointer.c	\

OBJS = ${FILES:.c=.o}

all: ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.o .c:
	cc -Wall -Werror -Wextra ${OBJS}

.Phony : all, clean, fclean, re, bonus
