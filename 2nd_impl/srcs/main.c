/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:55 by fbarros           #+#    #+#             */
/*   Updated: 2021/06/11 16:04:19 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*---------------TEMPORARY-----------------*/

/*static*/ void printlst(t_dlist *tmp)
{
	printf("--------\n");
	if (!tmp)
	{
		printf("Empty!\n");
		return ;
	}
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	printf("--------\n");
}
/*---------------TEMPORARY-----------------*/


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
			if (ft_isspace(arg[i][j]))
				continue ;
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

static void	get_nums(char **argv, t_stack *a, int *n, int argc)
{
	a->size = 0;
	a->head = NULL;

	if (argc == 2)
	{
		a->size = 0;
		argv = ft_split(argv[1], ' ');
		if (!argv)
			display_err();
		while (argv[a->size])
		{
			n[a->size] = ft_atoi(argv[a->size]);
			free(argv[a->size++]);
		}
		free(argv);
	}
	else
	{
		while (a->size < argc && argv[a->size + 1])
		{
			n[a->size] = ft_atoi(argv[a->size + 1]);
			a->size++;
		}
	}
}

int	main(int argc, char **argv)
{
	int		n[argc - 1];
	t_stack	a;
	int		i;
	int		j;


	if (!arg_check(argv + 1))
		display_err();	
	get_nums(argv, &a, n, argc);/*IF $ARG used argc == 2 ---> strsplit*/
	if(!num_check(n, a.size))
		display_err();
	i = a.size;
	while (i-- > 0)
	{
		lstadd_front(&a.head, lstnew(n[i]));
		if (!a.head)
			display_err();
	}
	if (!search(a) && a.size) // <--------------malloc'ing the whole list just to check if ordered not clever. ---> Check beforehand <---
	{
		/*--------------TEST ZONE------------------*/
/*		printf("stack a:\n");
		printlst(a.head);*/
//		quick_sort(&a);
//		if (a.size <= 5)
			sort_small(&a, b_init());
//		else
//			radix_sort(&a, b_init());
//		printlst(a.head);
/*		t_stack b = b_init();
		exec("pb", &a, &b);
		exec("pb", &a, &b);
		exec("ra", &a, &b);
		printf("stack b:\n");
		printlst(b.head);
		exec("rra", &a, &b);

		printf("stack b:\n");
		printlst(b.head);
*/	/*	printf("stack a:\n");
		printlst(a.head);
*/


//		PRINT REVERSE <-------------
/*		printf("reverse stack a:\n");
			printf("--------\n");
		t_dlist *tmp;
		tmp = lstlast(a.head);
		if (!tmp)
		{
			printf("Empty!\n");
		}
		while (tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->prev;
		}
		printf("--------\n");
*/
	/*--------------TEST ZONE------------------*/

	}
	lstclear(&a.head);
	return (0);
}
