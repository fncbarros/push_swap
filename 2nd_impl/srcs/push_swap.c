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

static void	b_init(t_stack *s)
{
	s->b = NULL;
	s->blen = 0;
}

/*---------->can't remember it's use........<--------------*/
/*
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
*/
/*????????????????????????????????????????????????????????????????*/
/*
void	quick_sort(t_stack *s)
{
	int 	first;
	int		second;
	int		range;
	int		i;

	i = 0;
	range = s->alen / 5;
	while (i++ < 5)
	{
		hold(s, &first, &second, range - (range * i), range * i);
		if (first < second)
		{
			while (first--)
				exec("ra", s);
		}
		else
		{
			while (second--)
				exec("rra", s);
		}
		exec("pb", s);
	}
}
*/
