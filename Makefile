# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarros <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 12:37:29 by fbarros           #+#    #+#              #
#    Updated: 2021/05/16 12:48:29 by fbarros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(wildcard *.c)

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

CC		= gcc -o

RM		= rm -f

LIBFT	= ./libft/libft.a

LIBFTOBJS	= $(wildcard ./libft/*.o)

all:		$(NAME)

$(LIBFT):
			$(MAKE) libft.a -C ./libft
			cp ./libft/libft.a .

.c.o:
			$(CC) $(NAME) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(LIBFT) $(OBJS)
			ar -x $(LIBFT)
	
clean:
			make clean -C ./libft
			$(RM) *.o $(OBJS)

fclean:
			$(RM) $(NAME) $(LIBFT)

re:			fclean all

.PHONY:	all clean fclean re
