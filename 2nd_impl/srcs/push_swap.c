/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:00:45 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/29 17:45:47 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	b_init(t_stack *b)
{
	b->head = NULL;
	b->size = 0;
}

static int	hold(t_stack *s, int *i, int *j, int min, int max)
{
	while (i++ != (s->size / 2) && s.head)
	{
		if (*(int *)s->content >= min && *(int *)s->content < max)
			break ;
		s = s->next;
	}
	j = s->size / 2;
	while (s.head)
	{
		if (*(int *)s->content >= min && *(int *)s->content < max)
			j = ;
		s = s->next;
		j++;
	}
	return(j);
}

void	quick_sort(t_stacks *a)
{
	int 	first;
	int		second;
	int		range;
	int		i;

	i = 0;
	range = a->size / 5;
	while (i++ < 5)
	{
		hold(a, &first, &second, range - (range * i), range * i);
		if (first < second)
		{
			while (first--)
				exec("ra", a, 0);
		}
		else
		{
			while (second--)
				exec("rra", a, 0);
		}
		exec("pb", a, &b);
	}
}
