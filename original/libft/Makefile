# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarros <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 14:41:52 by fbarros           #+#    #+#              #
#    Updated: 2021/05/16 12:37:01 by fbarros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(wildcard *.c)

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Werror -Wextra -g

NAME	= libft.a

CC	= gcc

AR	= ar rc

INDEX	= ranlib

RM	= rm -f

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

all:		$(NAME)

$(NAME):	${OBJS}
			${AR} $(NAME) ${OBJS}
			${INDEX} $(NAME)

clean :		
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}

re:			fclean all

rebonus :	fclean

.PHONY:		all clean fclean re
