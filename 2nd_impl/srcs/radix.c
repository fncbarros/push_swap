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

static int ft_rotate(t_stack *a, t_stack top, t_stack bottom)
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

static int	find_first(t_stack *a, int dec, int mod)
/*finds looked for element closest to extremes(top/bottom) and brings it to top
returns 0 if none found*/
{
	t_stack	top; 		//static???
	t_stack	bottom;

	if (!a->size)
		return (0);
	top.head = a->head;
	top.size = 0;
	bottom.size = a->size;
	while(top.head && top.size < ((a->size / 2) - 1))
	{
		if ((top.head->n % mod) == dec)
			break ;
		top.head = top.head->next;
		top.size++;
	}
	bottom.head = lstlast(top.head);					
	while (bottom.head && bottom.size-- > (a->size / 2))
	{
		if ((bottom.head->n % mod) == dec)
			break ;
		bottom.head = bottom.head->prev;
	}
	bottom.size = a->size - bottom.size;
	return (ft_rotate(a, top, bottom));
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	mod;
	int	dec;

	mod = 10;
/*	find_first(a, 1, 10);
	exec("pb", a, b);
	return ;
*/	while(!search(*a) || b->size)
	{
		dec = 0;
		while (dec < 9 && a->size) //do not want to empty stack_a entirely <-------
		{
			if (a->head->n % mod == dec)
				exec("pb", a, b);
			dec += find_first(a, dec, mod);
		}
		break ;
/*		while (b->size)
			exec("pa", a, b);
//		break ;
		mod *= 10;
*/	}	
	printf("stack b:\n");
	printlst(b->head);
	free(b);
}