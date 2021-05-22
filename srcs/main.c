/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:55 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/22 20:52:27 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

/*DEREFERENCE elements using *(int *)a.head->content */

static void	del(void *content)
{
	if (!content)
		return ;
	content = NULL;
}

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
		ft_lstadd_front(&a.head, ft_lstnew(&n[i]));
	if (!a.head)
		display_err();
	printf("%d\t%d\n", *(int *)a.head->content, *(int *)a.head->next->content);
	swap(&a.head);
	printf("%d\t%d\n", *(int *)a.head->content, *(int *)a.head->next->content);
	ft_lstclear(&a.head, del);
	return (0);
}
