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
	if (search(s, 'a'))
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

static int	num_check(char *arg)
{
	int 	i;
	int 	j;
	long	n;

	i = -1;
	n = ft_atoi(arg);
	j = i;
	if (n > INT_MAX || n < INT_MIN)
		display_err();
	return ;
}

static int	*arg_check(char **arg, int count)
/*MAX_INT MIN_INT ...:<-----------------------<limits.h>*/
{
	int i;
	int j;
	int n[count];
	int	k;

	i = 1;
	while (arg[i])
	{
		j = -1;
		if (arg[i][0] == '-')
			j++;
		while (arg[i][++j])
		{
			if (!ft_isdigit(arg[i][j]))
				return (NULL);
			n[i - 1] = num_check(arg[i]);
			k = -1;
			while (++k < (i - 1))
			{
				if (n[i - 1] == n[k])
					display_err();
			}
		}
		i++;
	}
	return (n);
}

/*static void	del(void *content)
{
	if (!content)
		return ;
	content = NULL;
}*/

int	main(int argc, char **argv)
{
	int	*n;
	t_stack	s;
	int	i;

	s.a = NULL;
	s.b = NULL;
	n = arg_check(argv + 1, argc - 1);
	if (argc < 3 || !n || )
		display_err();
	i = 0;
	s.alen = argc - 1;
	while (++i < argc)
		ft_lstadd_front(&s.a, ft_lstnew(n[i]));
	i--;
	if (!s.a)
		display_err();
	/*--test zone--*/

	printlst(s.a);
	exec("pb", &s);
	exec("pb", &s);
	printlst(s.a);
	printlst(s.b);
	exec("ra", &s);
	exec("rb", &s);
	printlst(s.a);
	printlst(s.b);

	check(s);

	/*--test zone--*/

//	ft_lstclear(&s.a, del);
	free(n);
	return (0);
}
