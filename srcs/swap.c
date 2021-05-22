/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:57:34 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/22 20:52:57 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_list **lst)
/*swaps upper 2 elements of stack*/
{
	t_list	*tmp;
//	t_list	*tmp2;

	if ((*lst)->next->next != NULL)
	{
		tmp = *lst;
//		tmp2 = *lst->next->next;
		*lst = (*lst)->next->next;
		tmp->next = *lst;
//		lst->next = lst->next->next;
//		tmp->next = lst;
//		tmp2->next = tmp;
	}
/*	else
	{
		lst->next->next = lst;
		lst->next = NULL;
	}
*/			
}
