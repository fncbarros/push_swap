/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:55 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/21 17:05:46 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		n[argc - 1];
	t_stack	a;
	int		i;

	i = 0;
	while (++i < argc)
		n[i - 1] = ft_atoi(argv[i]);
	a.size = argc - 1;
	while (i--)
		ft_lstadd_front(&a.head, ft_lstnew(&n[i])); //ADDING BOTTOM UP
	printf("%d\n", *(int *)a.head->content);
	ft_lstclear(&a.head, &free);
	return (0);
}
