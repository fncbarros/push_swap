#include "../inc/push_swap.h"

t_dlist	*lstnew(void *content)
{
	t_dlist	*lst;

	lst = NULL;
	lst = malloc(sizeof(lst));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->prev = NULL;
	lst->content = content;
	return (lst);
}

t_dlist	*lstlast(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_front(t_dlist **lst, t_dlist *new_elmt)
{
	t_dlist	*tmp;

	if (new_elmt != NULL || lst != NULL)
	{
		tmp = *lst;
		(*new_elmt).next = *lst;
		(*lst)->prev = new_elmt;
		*lst = new_elmt;
	}
}

void	lstdelone(t_dlist *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
	lst = NULL;
}

void	lstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*tmp;

	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
