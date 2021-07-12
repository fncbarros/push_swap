/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:02:02 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/12 15:45:48 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_lst *lst/*, void (*del)(void *)*/)
{
//	int	*tmp;

	if (!lst/* || !del*/)
		return ;
/*
	*tmp = lst->num;
	(*del)(tmp);
	tmp = NULL;
*/	free(lst);
	lst = NULL;
}
