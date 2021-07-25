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
/*finds midpoint in stack if odd or end of upper half if even
	not really useful atm*/
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

int ft_rotate(t_stack *a, int rot, char *dir)
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

int	find_closest(t_stack *a, int mod, int dec) 
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
		if ((top.head->n / mod) % 10 == dec)
			break ; 
		top.head = top.head->next;
	}
	bottom.head = lstlast(top.head);
	while (bottom.head && bottom.size <= (a->size / 2))
	{
		bottom.size++;
		if ((bottom.head->n / mod) % 10 == dec && bottom.size < top.size)
			return (ft_rotate(a, bottom.size, "rra"));
		bottom.head = bottom.head->prev;
	}
	if (top.size > (a->size / 2) && (top.head->n / mod) % 10 != dec)
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