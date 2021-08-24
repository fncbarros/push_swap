#include "../inc/push_swap.h"

t_dlist	*lstnew(int content, t_stack *s)
{
	t_dlist	*lst;

	lst = NULL;
	lst = (t_dlist *)malloc_n_check(sizeof(t_dlist), s);
	lst->next = NULL;
	lst->prev = NULL;
	lst->n = content;
	lst->index = 0;
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

void	lstadd_front(t_stack *s, t_dlist *new_elmt)
{
	if (!s->head)
	{
		s->head = new_elmt;
		s->last = new_elmt;
		return ;
	}
	else if (new_elmt)
	{
		new_elmt->next = s->head;
		s->head->prev = new_elmt;
		s->head = new_elmt;
	}
}

void	lstclear(t_dlist **lst)
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
