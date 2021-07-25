/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:15:22 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/29 16:16:48 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	display_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	search(t_stack s)
/*...or int search(t_stack *s)??
 * return 0 if out of order
 *if s.head->next != NULL
	return i is a bit useless
 * */
{
	ssize_t	i;

	if (!s.head)
		return (0);
	i = 1;
	while (s.head->next &&
		s.head->n < s.head->next->n)
	{
		s.head = s.head->next;
		i++;
	}
	if (s.size != i)
		return (0);
	else
		return (i);
}

static t_dlist	*get_middle(t_stack a)
{
	t_dlist	*tmp;
	int		i;

	i = 0;
	tmp = a.head;
	while(i++ < (a.size / 2))
		tmp = tmp->next;
/*	printf("\nMIDDLE: %d\n\n", *(int *)tmp->content);*/ //<------ REMOVE
	return (tmp);
}

int ft_rotate(t_stack *a, t_stack top, t_stack bottom)
{
	ssize_t	rot;
	char 	*dir;

	dir = "rra";
	rot = bottom.size;
	if (top.size >= ((a->size / 2) - 1) && bottom.size >= (a->size / 2))
		return (1);
	if (top.size == (bottom.size - 1))
	/*if top == bottom choose smallest btween upper and lower*/
	{
		if (top.head->n < bottom.head->n)
		{
			dir = "ra";
			rot = top.size;
		}
	}
	else if (top.size < bottom.size)
	{
		dir = "ra";
		rot = top.size - 1;
	}
	while (rot-- > 0)
		exec(dir, a, 0);
	return (0);
}

int	find_closest(t_stack *a, int	condition) 
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
		if (top.head->n == condition)
			break ; 
		top.head = top.head->next;
	}

	bottom.head = lstlast(top.head);
	while (bottom.head && bottom.size <= (a->size / 2))
	{
		bottom.size++;
		if (bottom.head->n == condition && bottom.size < top.size)
			return (bottom.size); //return (rotate function)
		bottom.head = bottom.head->prev;
	}
	if (top.size > (a->size / 2) && top.head->n != condition)
		top.size = 0;		
	/*if tmp.size > i: tmp.size = i*/
	printf("\ntop = %d\tbottom = %d\t", top.size, bottom.size);
	return (--top.size); //return (rotate function)
/*return (ft_rotate(a, top, bottom));*/
}

/* ^^^ ------------------------------------------------------------------------------ ^^^
		maybe pass a copy of a->head to save a line (t_dlist a, int condition)
		maybe return absolute index number instead of relative to top/bottom (0 - a.size) 
		... or call a rotating function instead
		...or pass char rot == "ra" or "raa" depending on value returned
   ^^^ ------------------------------------------------------------------------------ ^^^	*/