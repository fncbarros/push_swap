/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:24:39 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/22 20:24:43 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	find_first(t_stack *a, char **rot)
/*Not without douby linked list*/
{
	t_list	*up;
	t_list	*low;

	up = a->head;
	low = ft_lstlast(a);
	while()
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	mod;
	int	dec;
	char	*rot;

	rot = "rra";
	mod = 10;
	while(!search(*a) || b->size)
	{
		dec = 0;
		find_first(*a, &rot);
	}
	free(b);
	return ;
}
