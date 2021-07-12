/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:52:40 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/12 14:39:38 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_lst *lst, void (*f)(int))
{
	if (lst)
	{
		if (lst->next != NULL)
		{
			f(lst->num);
			ft_lstiter(lst->next, f);
		}
		else
			f(lst->num);
	}
	return ;
}
