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

/*---------------TEMPORARY-----------------*/

void	printlst(t_stack *s, char arg)
{
	t_dlist	*tmp;

	if (arg == 'r')
	{
		tmp = s->last;
		printf("REVERSE\n");
	}
	else
		tmp = s->head;
	printf("--------\n");
	if (!tmp)
	{
		printf("Empty!\n");
		return ;
	}
	while (tmp)
	{
		if (arg == 'i')
			printf("(index)%d\n", tmp->index);
		else
			printf("%d\n", tmp->n);
		if (arg == 'r')
			tmp = tmp->prev;
		else
			tmp = tmp->next;
	}
	printf("--------\n");
}
/*---------------TEMPORARY-----------------*/

static int	arg_check(char **arg)
/*MAX_INT MIN_INT ...:<-----------------------------*/
{
	int	i;
	int	j;

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
			/*neg flag*/
				a->neg = 1;
		}
	}
	return (1);
}

static int	get_index(int number, int *index, int size, int len)
/*Binary search
int len very stupid idea*/
{
	int	i;

	i = size / 2;
	if (i <= 0)
		return (0);
	else if (i >= len)
		return (len);
	if (number != index[i])
	{
		if (number < index[i])
			return (get_index(number, index, i, len));
		else
		{
//			printf("size+i: %d\n", size+i);
			return (get_index(number, index, size + (i + 1), len));
		}
	}
	return (i);
}

static void	get_nums(char **argv, t_stack *a, int *n, int argc)
{
	char	**arg;

	a->head = NULL;
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
			n[a->size] = _atoi(arg[a->size]);
			free(arg[a->size++]);
		}
		free(arg);
	}
	else
	{
		while (a->size < argc && argv[a->size + 1])
		{
			n[a->size] = _atoi(argv[a->size + 1]);
			a->size++;
		}
	}
}

int	main(int argc, char **argv)
/*Replace variable length array n[argc-1]
 * Too many lines*/
{
	int	*n; //malloc argc -1 elements
	int	i;
	t_dlist	*tmp;
	t_stack	a;
	t_stack	b;

	b.size = 0;
	n = (int *)malloc(sizeof(int) * (argc));
	if (!n)
		display_err();
	if (!arg_check(argv + 1))
		display_err();
	get_nums(argv, &a, n, argc);
	if (a_search(n, a.size))
		return (0);
	if (!num_check(n, a.size, &a))
		display_err();
	i = a.size;
	while (i-- > 0)
	{
		lstadd_front(&a, lstnew((int)n[i]));
		if (!a.head)
			display_err();
	}
	tmp = a.head;
	quicksort(n, 0, a.size);
	
	/*----------------------*/
	i = -1;
	while (++i < a.size)
		printf("%d\n", n[i]);
	/*---------------------*/
	
//	if (a.size > SHORT_LST /*&& a.neg*/) //Not to execute if no negatives on list; CREATE NEG FLAG ON T_STACK -> NEVERMIND
	{
		while (tmp)
		{
			// printf("--> going through TMP\n");
			tmp->index = 1 + get_index(tmp->n, n, a.size, a.size);
			tmp = tmp->next;
		}
//		tmp->index = 1 + get_index(tmp->n, n, a.size, a.size);
	}


	/*--------------TEST ZONE------------------*/
		printf("stack a:\n\n");
		printlst(&a, 0);
		printlst(&a, 'i');
	if (a.size <= SHORT_LST)
		sort_small(&a, &b);
	else
		radix_sort(&a, &b);
		printf("stack a:\n");
		printlst(&a, 0);
		printlst(&a, 'i');
	/*--------------TEST ZONE------------------*/
	free(n);
	lstclear(&a.head);
	return (0);
}
