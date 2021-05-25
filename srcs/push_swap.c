/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:39:07 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/25 14:09:52 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exec(char *arg, t_stack *a, t_stack *b)
{
	char	r;
	int	i;

	r = 0;
	i = 0;
	if (ft_strnstr(arg, "pa", 2))
		push(b, a);
	else if (ft_strnstr(arg, "pb", 2))
		push(a, b);
	else if (*arg == 's')
	{
		if (*(arg + 1) == 'a' || *(arg + 1) == 's')
			swap(&a->head);
		if (*(arg + 1) == 'b' || *(arg + 1) == 's')
			swap(&b->head);
	}
	else if (*arg == 'r')
	{
		if (ft_strlen(arg) == 3)
		{
			r = 'r';
			i++;
		}
		if (*(arg + i) == 'a' || *(arg + i) == 'r')
			rotate(&a->head, r);
		if ( *(arg + i)== 'b' || *(arg + i) == 'r')
			rotate(&b->head, r);
	}
	ft_putstr_fd(arg, 1);
}	
