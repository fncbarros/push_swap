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
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	tmp = a->head;
	tmp2 = tmp;
	i = 0;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
		if (*(int *)tmp->content > *(int *)tmp2->content)
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
	while (!search(*a) || b->size)
	{
		top = *(int *)a->head->content;
		bottom = *(int *)ft_lstlast(a->head)->content;
		if (top > bottom)
			exec("ra", a, 0);
		else if (top > *(int *)a->head->next->content)
			exec("sa", a, 0);
		else if (*(int *)a->head->next->content > bottom)
			exec("rra", a, 0);
		if (b->size && search(*a))
			exec("pa", a, b);
	}
	free(b);
}
