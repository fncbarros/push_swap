/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:55 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/24 19:28:59 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

/*DEREFERENCE elements using *(int *)a.head->content */

static void check(t_stack s)
{
	if (search(s))
		printf("ordered");
	else
		printf("unordered");
}

static void printlst(t_list *tmp)
{
	printf("--------\n");
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("--------\n");
}

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
	i--;
	while (i--)
		ft_lstadd_front(&a.head, ft_lstnew(&n[i]));
	if (!a.head)
		display_err();

	/*--test zone--*/
	printlst(a.head);
	rotate(&a.head, 0);
	printlst(a.head);
	check(a);
	/*--test zone--*/

	ft_lstclear(&a.head, del);
	return (0);
}
