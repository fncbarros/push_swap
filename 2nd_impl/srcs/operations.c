/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:39:07 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/04 23:06:26 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	op_rotate(char *arg, t_stack *a, t_stack *b)
{
	int	r;
	int	i;

	i = 0;
	r = 0;
	if (ft_strlen(arg) == 3)
	{
		r = 'r';
		i++;
	}
	if (*(arg + i) == 'a' || *(arg + i) == 'r')
		rotate(a, r);
	else if (*(arg + i) == 'b' || *(arg + i) == 'r')
		rotate(b, r);
}

void	exec(char *arg, t_stack *a, t_stack *b)
{
	if (ft_strnstr(arg, "pa", 2))
		push(b, a);
	else if (ft_strnstr(arg, "pb", 2))
		push(a, b);
	else if (*arg == 's')
	{
		if (*(arg + 1) == 'a' || *(arg + 1) == 's')
			swap(a);
		if (*(arg + 1) == 'b' || *(arg + 1) == 's')
			swap(a);
	}
	else if (*arg == 'r')
		op_rotate(arg, a, b);
	ft_putendl_fd(arg, 1);
}
