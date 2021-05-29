/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:27:16 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/29 14:48:21 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	search(t_stack s)
/*...or int search(t_stack *s)??
 * return 0 if out of order
 *if s.head->next != NULL
	return i is a bit useless
 * */
{
	ssize_t	i;

	i = 1;
	while (s.head->next &&
		*(int *)s.head->content < *(int *)s.head->next->content)
	{
		s.head = s.head->next;
		i++;
	}
	if (s.size != i)
		return (i);
	else
		return (0);
}
