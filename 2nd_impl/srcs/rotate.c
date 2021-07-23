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

void	rotate(t_dlist **lst, char r, char *arg)
/*NOT WORKING W/ 2 ELEMENTS ONLY*/
{
	t_dlist	*first;
	t_dlist	*last;

	if (!(*lst)->next || !(*lst))
		return ;
	last = lstlast(*lst);
	first = *lst; //pointing to first element
	if (r != 'r')
	{
		*lst = (*lst)->next;
		first->next = NULL;
		last->next = first;
	}
	else
	{
		while (first->next != last)
			first = first->next;
		first->next = NULL;
		last->next = *lst;
		*lst = last;
	}
	ft_putstr_fd(arg, 1);
}
