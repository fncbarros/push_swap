/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:57:34 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/23 12:52:37 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *s)
/*swaps upper 2 elements of stack*/
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	tmp = s->head->next;
	if (s->head->next->next != NULL)
		tmp2 = s->head->next->next;
	s->head->prev = tmp;
	s->head->next = tmp2;
	tmp2->prev = s->head;
	tmp->prev = NULL;
	tmp->next = s->head;
	s->head = tmp;
}
