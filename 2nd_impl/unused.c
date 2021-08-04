/*Unused files cuz I ran out of time*/

#include "inc/push_swap.h"

static int ft_rotate(t_stack *a, int rot, char *dir)
/*rotates a rot times in dir direction
	does nothing and returns 1 if rot is -1
only working for stack a atm; not very versatile*/
{
	if (rot == -1)
		return (1);
	while (rot--)
		exec(dir, a, 0);
	return (0);
}

static int	find_closest(t_stack *a, int i)
/*finds looked for element closest to extremes(top/bottom) and brings it to top
returns -1 if none found*/
{
	t_stack		top;
	t_stack		bottom;

	if (!a->size)
		return (0);
	top.head = a->head;
	top.size = 0;
	bottom.size = 0;
	while (top.head && top.size++ < (a->size / 2))
	{
		if (!((top.head->n >> i) & 1))
			break ;
		top.head = top.head->next;
	}
	bottom.head = lstlast(top.head);
	while (bottom.head && bottom.size <= (a->size / 2))
	{
		bottom.size++;
		if (!((bottom.head->n >> i) & 1) && bottom.size < top.size)
			return (ft_rotate(a, bottom.size, "rra"));
		bottom.head = bottom.head->prev;
	}
	if (top.size > (a->size / 2) && ((top.head->n >> i) & 1))
		top.size = 0;
	/*if tmp.size > i: tmp.size = i*/
//	printf("\ntop = %d\tbottom = %d\t", top.size, bottom.size);
	return (ft_rotate(a, --top.size, "ra"));
/*return (ft_rotate(a, top, bottom));*/
}

/* ^^^ ------------------------------------------------------------------------------ ^^^
		maybe pass a copy of a->head to save a line (t_dlist a, int condition)
		maybe return absolute index number instead of relative to top/bottom (0 - a.size)
		... or call a rotating function instead
		...or pass char rot == "ra" or "raa" depending on value returned
   ^^^ ------------------------------------------------------------------------------ ^^^	*/


t_dlist	pop(t_stack *s)
/*
 * Deletes 1st node on stack pointed to by s->head
 * Returns same node*/
{
	t_dlist	*node;

	node = s->head;	/*node points to 1st element of stack*/
	node->next = NULL;	/*isolates element*/
	s->head = s->head->next;	/*stack head points to next element*/
	s->size--;	/*size "decrement"*/
	return (*node); /*return element pointed to by "node"*/
}


static int	chunk_sort(t_stack *s, int *i, int *j, int min, int max)
/*NOT WORKING*/
{
	int	tmp;

	while ((*i)++ != (int)(s->size / 2) && s->head)
	{
		if (s->head->n >= min && s->head->n < max)
			break ;
		s->head = s->head->next;
	}
	tmp = *i;
	while (tmp++ != s->size)
		s->head = s->head->next;
	tmp = s->size / 2;
	*j = 0;
	while (s->head)
	{
		if (s->head->n >= min && s->head->n < max)
			*j = tmp;
		s->head = s->head->next;
		tmp++;
	}
	if (*i == (int)(s->size / 2) && *j == 0)
		return(0);
	else
		return (1);
}

void	quick_sort(t_stack *a, t_stack *b)
/*NOT WORKING*/
{
	int 	first;
	int		second;
	int		range;
	int		i;

	i = 0;
	range = a->size / 5;
	while (i++ < 5)
	{
		while (chunk_sort(a, &first, &second, range - (range * i), range * i))
		{
			if (first <= second)
			{
				while (first--)
					exec("ra", a, 0);
			}
			else
			{
				while (second--)
					exec("rra", a, 0);
			}
			exec("pb", a, b);
		}
	}
	printf("stack b:\n");
	printlst(b, 0);
	printf("stack b:\n");
	free(b);
}
