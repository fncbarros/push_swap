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

static t_list	*get_middle(t_stack a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = a.head;
	while(i++ < (a.size / 2))
		tmp = tmp->next;
/*	printf("\nMIDDLE: %d\n\n", *(int *)tmp->content);*/ //<------ REMOVE
	return (tmp);
}

static int ft_rotate(t_stack *a, int top, int bottom)
{
	int		rot;
	char 	*dir;

	dir = "rra";
	rot = bottom;
	if (top >= (a->size / 2) && !bottom)
		return (0);
	if (top < bottom)
	{
		dir = "ra";
		rot = top;
	}
	while (rot--)
		exec(dir, a, 0);
	return (1);
}

static int	find_first(t_stack *a, int dec, int mod)
/*finds looked for element closest to extremes(top/bottom) and brings it to top
return 0 if none found*/
{
	t_list	*tmp;
	t_list	*tmp2;
	int		top;
	int		x;
	int		bottom;

	if (!a->size)
		return (0);
	tmp = a->head;
	top = 0;
	x = a->size / 2;
	while(tmp && top++ < (a->size / 2))
	{
		if (*(int *)tmp->content % mod == dec)
			break ;
		tmp = tmp->next;
	}
	tmp = get_middle(*a);
	while (tmp && --x)
	{
		if (*(int *)tmp->content % mod == dec)
		{
			bottom = x;
			tmp2 = tmp;
		}
		tmp = tmp->next;
	}
	return (ft_rotate(a, top, bottom));
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	mod;
	int	dec;

	mod = 10;
	find_first(a, 1, 10);

	while(!search(*a) || b->size)
	{
		dec = 1;
		while (dec < 9)
		{
			if (!find_first(a, dec, mod))
				dec++;
			exec("pb", a, b);
		}
		while (b->size)
			exec("pa", a, b);
		break ;
	}
	printf("stack b:\n");
	printlst(b->head);
	free(b);
}
