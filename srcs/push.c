/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:40:30 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/22 18:57:29 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack *src, t_stack *dst)
/*
 * Pushes src to dst
 *Add node to list pointed by stack's head s
 increment stack size
 does not pop from previous t_list, ...
 updates sizes of both stacks*/
{
	t_dlist	*tmp;

	if (!src->head)
		return ;
	tmp = src->head;
	src->head = src->head->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (!dst->size)
	{
		dst->head = tmp;
		dst->last = tmp;
	}
	else
		lstadd_front(dst, tmp);
	if (src->head)
		src->head->prev = NULL;
	if (src->size == 1)
		src->last = NULL;
	dst->size++;
	src->size--;
}
