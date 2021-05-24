/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:24:07 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/24 18:44:40 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

//	last = ft_lstlast(*lst);
	last = *lst; //pointing to last element
	while (last->next != 0)
		last = last->next;
	tmp = *lst; //pointing to first element
	*lst = (*lst)->next;
	tmp->next = NULL;
	last->next = tmp;
}
