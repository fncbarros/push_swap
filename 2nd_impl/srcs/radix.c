/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:24:39 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/04 23:08:26 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
/*line 32: using index instead of value
line 34: Don't want to rotate on last check*/
{
	int	bit_range;
	int	i;
	int	j;
	int	size;

	i = 0;
	size = a->size;
	while (a->size >> bit_range)
		bit_range++;
	while ((!s_search(*a) || b->size) && (i <= bit_range))
	{
		j = size + 1;
		while (j-- && a->size)
		{
			if (((a->head->n >> i) & 1) == 0) /*CHANGE TO INDEX*/
				exec("pb", a, b);
			else if (j)
				exec("ra", a, b);
		}
		while (b->size)
			exec("pa", a, b);
		i++;
	}
}
