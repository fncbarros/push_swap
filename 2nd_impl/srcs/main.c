/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:55 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/24 15:35:21 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*---------------TEMPORARY-----------------*/
void printlst(t_dlist *tmp)
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
			if (ft_isspace(arg[i][j]) || arg[i][j] == '-')
				continue ;
			if (!ft_isdigit(arg[i][j]))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	num_check(const double *n, int len/*, int *copy*/)
{
	int i;
	int j;

	i = -1;
	while (++i < len)
	{
//		copy[i] = n[i];
		if (n[i] > INT_MAX || n[i] < INT_MIN)
			display_err();
		j = i;
		while (++j < len)
		{
			if (n[i] == n[j])
				return (0);
		}
	}
//	if (len > SHORT_LST) /*bypass in case size < 5*/
//		copy = sort_array(n, len); //still need to build; if sorted ??
	return (1);
}

static int	get_index(int number, int *index, int size)
/*Binary search*/
{
	int	i;

	i = size / 2;
	if (i < 0 || i >= size || !index[i])
		return (0);
	if (number != index[i])
	{
		if (number < index[i])
			return(get_index(number, index, i));
		else
			return(get_index(number, index , size + (i + 1)));
	}
	return (i + 1);
}

static void	get_nums(char **argv, t_stack *a, double *n, int argc)
{
	char	**arg;

	a->size = 0;
	arg = NULL;
	if (argc == 2)
	{
		a->size = 0;
		arg = ft_split(argv[1], ' ');
		if (!arg)
			display_err();
		while (arg[a->size])
		{
			n[a->size] = ft_atoi(arg[a->size]);
			free(arg[a->size++]);
		}
		free(arg);
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
	double	n[argc - 1];
	t_stack	a;
//	int		sorted[argc - 1];
	int		i;
	t_stack	b;

	a.head = NULL;
	b.size = 0;
	if (!arg_check(argv + 1))
		display_err();
	get_nums(argv, &a, n, argc);
	if (a_search(n, a.size))
		return (0);
	if(!num_check(n, a.size/*, sorted*/))
		display_err();
	i = a.size;
	while (i-- > 0)
	{
		lstadd_front(&a, lstnew((int)n[i]));
		if (!a.head)
			display_err();
//		if (a.size > SHORT_LST) //Not to execute if no negatives on list
//			a.head->index = get_index(n[i], sorted, a.size); /*NEED SORT ARRAY <-------- bypass if size < 5*/
	}
	/*--------------TEST ZONE------------------*/
//		printf("stack a:\n\n");
//		printlst(a.head);
		if (a.size <= SHORT_LST)
			sort_small(&a, &b);
		else
			radix_sort(&a, &b);
//		printf("stack a:\n");
//		printlst(a.head);

	/*--------------TEST ZONE------------------*/
	lstclear(&a.head);
	return (0);
}
