# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:55:13 by casomarr          #+#    #+#              #
#    Updated: 2022/11/30 14:55:13 by casomarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_isalpha.c	\
	ft_isalnum.c		\
	ft_isdigit.c		\
	ft_isascii.c		\
	ft_isprint.c		\
	ft_memset.c			\
	ft_bzero.c			\
	ft_memcpy.c			\
	ft_strlcpy.c		\
	ft_strlcat.c		\
	ft_toupper.c		\
	ft_tolower.c		\
	ft_strchr.c			\
	ft_strrchr.c		\
	ft_strncmp.c		\
	ft_memchr.c			\
	ft_memcmp.c			\
	ft_strnstr.c		\
	ft_atoi.c 			\
	ft_calloc.c			\
	ft_strdup.c			\
	ft_memmove.c 		\
	ft_substr.c			\
	ft_strjoin.c		\
	ft_strtrim.c		\
	ft_split.c			\
	ft_itoa.c			\
	ft_strmapi.c		\
	ft_striteri.c		\
	ft_putchar_fd.c		\
	ft_putstr_fd.c		\
	ft_putendl_fd.c		\
	ft_putnbr_fd.c		\
	ft_strlen.c			\

OBJS = ${FILES:.c=.o}

FILES_BONUS = ft_lstadd_back.c 		\
		ft_lstadd_front.c 			\
		ft_lstdelone.c  			\
		ft_lstlast.c  				\
		ft_lstnew.c  				\
		ft_lstsize.c				\
		ft_lstiter.c				\
		ft_lstclear.c				\
		ft_lstmap.c					\

OBJS_BONUS = $(FILES_BONUS:.c=.o)

all: ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus : $(OBJS_BONUS)
	ar rc ${NAME} ${OBJS_BONUS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME} ${OBJS_BONUS}

re : fclean all

.c.o:
#cc -Wall -Werror -Wextra ${OBJS}
	cc -Wall -Werror -Wextra -c $< -o $(<:.c=.o)

.Phony : all, clean, fclean, re, bonus
