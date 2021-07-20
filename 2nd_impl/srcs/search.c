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

int	search(t_stack s, char c)
/*...or int search(t_stack *s)??
 * return 0 if out of order
 *if s.head->next != NULL
	return i is a bit useless
 * */
{
	ssize_t	i;
	ssize_t	r;
	t_lst	*h;

	i = 1;
	h = s.a;
	r = s.alen;
	if(c == 'b')
	{
		h = s.b;
		r = s.blen;
	}
	while (h->next &&
		h->num < h->next->num)
	{
		h = h->next;
		i++;
	}
	if (r != i)
		return (i);
	else
		return (0);
}
