/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:53:15 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/12 15:47:13 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstmap(t_lst *lst, int (*f)(int)/*, void (*del)(void *)*/)
{
	t_lst	*new;
	t_lst	*newroot;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->num));
	if (!new)
		return (NULL);
	newroot = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(f(lst->num));
		if (new->next == NULL)
		{
			ft_lstclear(&new/*, del*/);
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (newroot);
}
