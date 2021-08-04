/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:24:07 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/24 19:28:06 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"



void	rotate(t_stack *s, char r)
/*NOT WORKING W/ 2 ELEMENTS ONLY*/
{
	t_dlist	*tmp;

	if (!s->head->next || !s->head)
		return ;
	tmp = s->head;
	if (r != 'r')
	{
		s->head = s->head->next;
		s->head->prev = NULL;
		tmp->next = NULL;
		tmp->prev = s->last;
		s->last->next = tmp;
		s->last = tmp;
	}
	else
	{
		tmp = s->last;
		s->last = s->last->prev;
		s->last->next = NULL;
		tmp->next = s->head;
		tmp->prev = NULL;
		s->head->prev = tmp;
		s->head = tmp;
	}
}
