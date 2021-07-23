/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:39:07 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/29 16:01:14 by fbarros          ###   ########.fr       */
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
		push(b, a, arg);
	else if (ft_strnstr(arg, "pb", 2))
		push(a, b, arg);
	else if (*arg == 's')
	{
		if (*(arg + 1) == 'a' || *(arg + 1) == 's')
			swap(&a->head, arg);
		if (*(arg + 1) == 'b' || *(arg + 1) == 's')
			swap(&b->head, arg);
	}
	else if (*arg == 'r')
	{
		if (ft_strlen(arg) == 3)
		{
			r = 'r';
			i++;
		}
		if (*(arg + i) == 'a' || *(arg + i) == 'r')
			rotate(&a->head, r, arg);
		else if ( *(arg + i)== 'b' || *(arg + i) == 'r')
			rotate(&b->head, r, arg);
	}
	ft_putchar_fd('\n', 1);
}
