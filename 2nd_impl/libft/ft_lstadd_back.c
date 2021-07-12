/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:44:24 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/12 15:40:02 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (!new || !lst)
		return ;
	last = ft_lstlast(new);
	last->next = NULL;
	if (*lst != NULL)
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
	else
	*lst = new;
}
