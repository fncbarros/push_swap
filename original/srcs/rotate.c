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

void	rotate(t_stack *stack, char r)
{
	t_list	*first;
	t_list	*last;

	if (stack->size < 3)
		return ;
	last = ft_lstlast(stack->head);
	first = stack->head;
	if (r != 'r')
	{
		stack->head = stack->head->next;
		first->next = NULL;
		last->next = first;
	}
	else
	{
		while (first->next != last)
			first = first->next;
		first->next = NULL;
		last->next = stack->head;
		stack->head = last;
	}
}
