#include "../inc/push_swap.h"

t_dlist	*lstnew(int content)
{
	t_dlist	*lst;

	lst = NULL;
	lst = (t_dlist *)malloc(sizeof(t_dlist));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->prev = NULL;
	lst->n = content;
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
	if (!(*lst))
	{
		*lst = new_elmt;
		return ;
	}
	if (new_elmt != NULL)
	{
		(*new_elmt).next = *lst;
		(*lst)->prev = new_elmt;
		*lst = new_elmt;
	}
}
/*
void	lstdelone(t_dlist *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	(*del)(lst->n);
	free(lst);
	lst = NULL;
}
*/
void	lstclear(t_dlist **lst/*, void (*del)(int)*/)
{
	t_dlist	*tmp;

	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
