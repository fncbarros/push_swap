/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:07:44 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/12 15:45:10 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_lst **lst/*, void (*del)(void *)*/)
{
	t_lst	*tmp;

	if (!*lst /*|| !del*/)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(lst);
	/*	ft_lstdelone(*lst, del);*/
		*lst = tmp;
	}
	*lst = NULL;
}
