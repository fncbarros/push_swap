/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:54:42 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/22 18:19:48 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	pop(t_stack *s)
/*
 * Deletes 1st node on stack pointed to by s->head
 * Returns same node*/
{
	t_list	*node;

	node = s->head;	/*node points to 1st element of stack*/
	node->next = NULL;	/*isolates element*/
	s->head = s->head->next;	/*stack head points to next element*/
	s->size--;	/*size "decrement"*/
	return (*node); /*return element pointed to by "node"*/
}
