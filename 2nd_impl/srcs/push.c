/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:40:30 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/12 14:50:46 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack *s, char c)
/*
 * Pushes src to dst
 *Add node to list pointed by stack's head s
 increment stack size
 does not pop from previous t_list, ...
 updates sizes of both stacks*/
{
	t_lst	*tmp;
	t_lst	*src;
	t_lst	*dst;

	if (!s || !c)
		return ;
	src = s->b;
	dst = s->a;
	if(c == 'b')
	{
		src = s->a;
		dst = s->b;
	}
	tmp = src;
	src = src->next;
	tmp->next = NULL;
	if (!dst)
		dst = tmp;
	else
		ft_lstadd_front(&dst, tmp);
}
