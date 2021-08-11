/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:55 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/04 23:18:14 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	arg_check(char **arg, int argc)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		exit(0);
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
			{
				ft_putendl_fd("Error", 2);
				exit (1);
			}
		}
		i++;
	}
}

static int	num_check(const int *n, int len, t_stack *a)
{
	int	i;
	int	j;

	i = -1;
	a->neg = 0;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (n[i] == n[j])
				return (0);
			if (!a->neg && n[i] < 0)
				a->neg = 1;
		}
	}
	return (1);
}

static void	get_nums(char **argv, t_stack *a, int *n, int argc)
{
	char	**arg;

	a->head = NULL;
	a->size = 0;
	arg = NULL;
	{
		while (a->size < argc && argv[a->size + 1])
		{
			n[a->size] = _atoi(argv[a->size + 1], a);
			a->size++;
		}
	}
}

static void	push_swap(t_stack *a, t_stack *b)
{
	t_dlist	*tmp;

	tmp = a->head;
	quicksort(a->arr, 0, a->size);
	if (a->size > SHORT_LST)
	{
		while (tmp)
		{
			tmp->index = (get_index(tmp->n, a->arr, a->size)) + 1;
			tmp = tmp->next;
		}
	}
	if (a->size <= SHORT_LST)
		sort_small(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;

	b.size = 0;
	a.arr = NULL;
	arg_check(argv + 1, argc - 1);
	a.arr = (int *)malloc_n_check(sizeof(int) * (argc), &a);
	get_nums(argv, &a, a.arr, argc);
	if (!num_check(a.arr, a.size, &a))
		display_err(&a);
	if (a_search(a.arr, a.size))
		return (0);
	i = a.size;
	while (i-- > 0)
		lstadd_front(&a, lstnew(a.arr[i], &a));
	push_swap(&a, &b);
	free(a.arr);
	lstclear(&a.head);
	return (0);
}
