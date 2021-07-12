/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:55 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/12 16:27:53 by fbarros          ###   ########.fr       */
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

static void printlst(t_lst *tmp)
{
	printf("--------\n");
	while (tmp)
	{
		printf("%d\n", tmp->num);
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

static int	num_check(int **n, int len, char **arg)
{
	int i;
	int j;

	i = -1;
	while (++i < len)
	{
		*n[i] = ft_atoi(arg[i + 1]);
		j = i;
		while (++j < len)
		{
			if (*n[i] == *n[j])
				return (0);
			if (*n[i] > INT_MAX || *n[i] < INT_MIN)
				return (0);
		}
	}
	return (1);
}

/*static void	del(void *content)
{
	if (!content)
		return ;
	content = NULL;
}*/

int	main(int argc, char **argv)
{
	int	n[argc - 1];
	t_stack	s;
	int	i;

	s.a = NULL;
	s.b = NULL;
	if (argc < 3 || !arg_check(argv + 1))
		display_err();
	int	*j = &n[0];
	if(!num_check(&n[], argc - 1, argv))
		display_err();
	i = 0;
	s.alen = argc - 1;
	while (++i < argc)
		ft_lstadd_front(&s.a, ft_lstnew(n[i]));
	i--;
	if (!s.a)
		display_err();
	/*--test zone--*/

	/*--test zone--*/

//	ft_lstclear(&s.a, del);
	
	return (0);
}
