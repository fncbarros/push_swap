/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:53:15 by fbarros           #+#    #+#             */
/*   Updated: 2021/03/18 11:26:41 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newroot;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	newroot = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(f(lst->content));
		if (new->next == NULL)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (newroot);
}
