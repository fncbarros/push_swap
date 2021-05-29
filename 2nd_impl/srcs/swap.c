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

void	swap(t_list **lst)
/*swaps upper 2 elements of stack*/
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = NULL;
	if ((*lst)->next->next != NULL)
		tmp = (*lst)->next->next;
	tmp2 = *lst;
	*lst = (*lst)->next;
	tmp2->next = tmp;
	(*lst)->next = tmp2;
}
