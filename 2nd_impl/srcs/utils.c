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

void	display_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int a_search(const int *a, int len)
{
	int	i;

	if (!a)
		return (0);
	i = 1;
	while (i < len)
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (i);
}

int	s_search(t_stack s)
/* searches stack or array
...or int search(t_stack *s)??
 * return 0 if out of order
 *if s.head->next != NULL
	return i is a bit useless
 * */
{
	ssize_t	i;

	if (!s.head)
		return (0);
	i = 1;
	while (s.head->next &&
		s.head->n < s.head->next->n)
	{
		s.head = s.head->next;
		i++;
	}
	if (s.size != i)
		return (0);
	else
		return (i);
}

static t_dlist	*get_middle(t_stack a)
/*finds midpoint in stack if odd or end of upper half if even
	not really useful atm*/
{
	t_dlist	*tmp;
	int		i;

	i = 0;
	tmp = a.head;
	while(i++ < (a.size / 2))
		tmp = tmp->next;
/*	printf("\nMIDDLE: %d\n\n", *(int *)tmp->content);*/ //<------ REMOVE
	return (tmp);
}

