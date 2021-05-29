/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:55 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/29 19:34:02 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

/*DEREFERENCE elements using *(int *)a.head->content */

/*---------------temporary-----------------*/
static void check(t_stack s)
{
	if (search(s))
		printf("ordered");
	else
		printf("unordered");
}

/*static*/ void printlst(t_list *tmp)
{
	printf("--------\n");
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("--------\n");
}
/*---------------temporary-----------------*/


static int	arg_check(char **arg)
/*MAX_INT MIN_INT ...:<-----------------------------*/
{
	int i;
	int j;

	i = 0;
	while (arg[i])
	{
		j = -1;
		if (arg[i][0] == '-')
			j++;
		while (arg[i][++j])
		{
			if (!ft_isdigit(arg[i][j]))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	num_check(int *n, int len)
{
	int i;
	int j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (n[i] == n[j])
				return (0);
		}
	}
	return (1);
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

	if (!arg_check(argv + 1)) /*IF $ARG used argc == 1*/
		display_err();
	i = 0;
	while (++i < argc)
		n[i - 1] = ft_atoi(argv[i]);
	if(!num_check(n, argc - 1))
		display_err();
	a.head = NULL;
	a.size = argc - 1;
	i--;
	while (i--)
		ft_lstadd_front(&a.head, ft_lstnew(&n[i]));
	if (!a.head)
		display_err();
	/*--test zone--*/
	printf("stack a:\n");
	printlst(a.head);
	quick_sort(&a);
	printf("stack a:\n");
	printlst(a.head);
	/*--test zone--*/

	ft_lstclear(&a.head, del);
	return (0);
}
