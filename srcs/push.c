/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:40:30 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/19 12:54:36 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_list *node, t_stack *s)
/*
 *Add node to list pointed by stack's head
 increment stack size
 does not pop from previous t_list, ...*/
{
	ft_lstadd_back(&(s->head), ft_lstnew(node));
	s->size++;
}
