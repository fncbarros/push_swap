/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:24:39 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/22 20:24:43 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//static int ft_rotate(t_stack *a, int rot, char *dir)
/*rotates a rot times in dir direction
	does nothing and returns 1 if rot is -1
only working for stack a atm; not very versatile*/
/*{
	if (rot == -1)
		return (1);
	while (rot--)
		exec(dir, a, 0);
	return (0);
}

static int	find_closest(t_stack *a, int i)*/
/*finds looked for element closest to extremes(top/bottom) and brings it to top
returns -1 if none found*/
/*{
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
		top.size = 0;*/
	/*if tmp.size > i: tmp.size = i*/
//	printf("\ntop = %d\tbottom = %d\t", top.size, bottom.size);
//	return (ft_rotate(a, --top.size, "ra"));
/*return (ft_rotate(a, top, bottom));*/
//}

/* ^^^ ------------------------------------------------------------------------------ ^^^
		maybe pass a copy of a->head to save a line (t_dlist a, int condition)
		maybe return absolute index number instead of relative to top/bottom (0 - a.size)
		... or call a rotating function instead
		...or pass char rot == "ra" or "raa" depending on value returned
   ^^^ ------------------------------------------------------------------------------ ^^^	*/
#define T 1 // REMOVE

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit_range;
	int	i;
	int	j;
	int	size;

	i = 0;
	size = a->size;
	while (a->size >> bit_range)
		bit_range++;
	while((!s_search(*a) || b->size) && (i <= bit_range))
	{
		j = size + 1;
		while (j-- && a->size)
		{
			if (((a->head->n >> i) & 1) == 0)
				exec("pb", a, b);
			else if (j) /*Don't want to rotate on last check*/
				exec("ra", a, b);
		}
//		if (i == T || i ==(T - 1))
//		{
			/* code */
//			printf("stack b iteration %d:\n", i);
//			printlst(b->head);
//		}
		while (b->size)
			exec("pa", a, b);
//		if (i == T ||  i == (T - 1))
//		{
			/* code */
//			printf("RADIX stack a:\n");
//			printlst(a->head);
//		}
		i++;

//		break ;
	}
}
//	printf("stack b:\n");
//	printlst(b->head);
//	lstclear(&b->head);
/*
		while (!find_closest(a, i))
			exec("pb", a, b);
		while (b->size)
			exec("pa", a, b);
		i++;
		printf("RADIX stack a:\n");
		printlst(a->head);*/