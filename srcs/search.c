/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:27:16 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/22 19:45:52 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	search(t_stack s)
/*...or int search(t_stack *s)??
 * return 0 if out of order
 * */
{
	ssize_t	i;

	i = 1;
	while (*(int *)s.head->content < *(int *)s.head->next->content && s.head->next)
	{
		s.head = s.head->next;
		i++;
	}
	if (s.size != i)	//if s.head->next != NULL
		return (0);
	else
		return (i);		//a bit useless
}
