# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarros <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 12:37:29 by fbarros           #+#    #+#              #
#    Updated: 2021/07/15 15:10:15 by fbarros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---TEMPORARY---#

#ARG	= $(ARG)

#---TEMPORARY---#

SRCS	= srcs/utils.c srcs/main.c srcs/operations.c srcs/pop.c srcs/push.c srcs/push_swap.c srcs/rotate.c srcs/swap.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

INCLUDE = inc/

NAME	= push_swap

CC		= gcc -o

RM		= rm -f

LIBFT	= libft.a

LIBFTOBJS	= $(wildcard ./libft/*.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(INCLUDE) $< -o $@

all:	$(NAME)

$(LIBFT):
		$(MAKE) libft.a -C ./libft
		cp ./libft/libft.a .


$(NAME):	$(LIBFT) $(OBJS)
		$(CC) $(NAME) $(OBJS) $(LIBFT) -o $(NAME)

#---TEMPORARY---#

debug:	$(LIBFT) $(OBJS)
		gcc $(CFLAGS) $(LIBFTOBJS) $(OBJS) -o debug

test:	debug
		lldb ./debug
#		process launch -- $(ARG)
#---TEMPORARY---#

clean:
			make clean -C ./libft
			$(RM) *.o $(OBJS)

fclean:		clean
			$(RM) $(NAME) $(LIBFT) libft/libft.a debug

re:			fclean all

.PHONY:	all clean fclean re test
