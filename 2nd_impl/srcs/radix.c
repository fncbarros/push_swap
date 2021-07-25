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

void	radix_sort(t_stack *a, t_stack *b)
{
	int	mod;
	int	dec;

	mod = 1;
/*	find_first(a, 1, 10);
	exec("pb", a, b);
	return ;
*/	while(!search(*a) || b->size)
	{
		dec = 9;
		while (dec > 9 && a->size) //do not want to empty stack_a entirely <-------
		{
			dec -= find_closest(a, mod, dec);
			if ((a->head->n / mod) % 10 == dec)
				exec("pb", a, b);
		}			
		while (b->size)
			exec("pa", a, b);
//		if (mod == 10)
//			break ;
		mod *= 10;
	}
/*	printf("stack b:\n");
	printlst(b->head);
	lstclear(&b->head);*/
}