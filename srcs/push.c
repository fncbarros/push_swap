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
	t_list	*tmp;

	if (!src->size)
		return ;
	tmp = src->head;
	src->head = src->head->next;
	tmp->next = NULL;
	if (!dst)
		dst->head = tmp;
	else
		ft_lstadd_front(&dst->head, tmp);
	dst->size++;
	src->size--;
}
