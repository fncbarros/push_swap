/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:15:22 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/29 16:16:48 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h> //<---------DEL

void	display_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_stack	b_init(void)
{
	t_stack	b;

	b.head = lstnew(NULL);
	b.size = 0;
	return (b);
}

int	search(t_stack s)
/*...or int search(t_stack *s)??
 * return 0 if out of order
 *if s.head->next != NULL
	return i is a bit useless
 * */
{
	ssize_t	i;

	i = 1;
	while (s.head->next &&
		*(int *)s.head->content < *(int *)s.head->next->content)
	{
		s.head = s.head->next;
		i++;
	}
	if (s.size != i)
		return (0);
	else
		return (i);
}
