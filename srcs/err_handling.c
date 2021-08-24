/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:39:28 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/11 10:39:31 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	display_err(t_stack *s)
{
	if (s)
		free(s->arr);
	if (s->head)
		lstclear(&s->head);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	*malloc_n_check(size_t block, t_stack *s)
{
	void	*p;

	p = malloc(block);
	if (!p)
		display_err(s);
	return (p);
}
