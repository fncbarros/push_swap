/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:55:31 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/22 17:55:36 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	find_smallest(t_stack *a)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;
	int		i;

	tmp = a->head;
	tmp2 = tmp;
	i = 0;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
		if (tmp->n > tmp2->n)
		{
			tmp = tmp2;
			i++;
		}
	}
	while (a->head != tmp)
	{
		if (i < (a->size / 2))
			exec("ra", a, 0);
		else
			exec("rra", a, 0);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	top;
	int	bottom;

	while (a->size > 3)
	{
		find_smallest(a);
		exec("pb", a, b);
	}
	while (!s_search(*a) || b->size)
	{
		top = a->head->n;
		bottom = lstlast(a->head)->n;
		if (top > bottom)
			exec("ra", a, 0);
		else if (top > a->head->next->n)
			exec("sa", a, 0);
		else if (a->head->next->n > bottom)
			exec("rra", a, 0);
		if (b->size && s_search(*a))
			exec("pa", a, b);
	}
}
