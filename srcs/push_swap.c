/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:00:45 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/29 19:34:07 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*-----REMOVE------*/
#include <stdio.h>
void printlst(t_list *tmp);
/*-----REMOVE------*/

static int	chunk_sort(t_stack *s, int *i, int *j, int min, int max)
{
	int	tmp;

	while ((*i)++ != (int)(s->size / 2) && s->head)
	{
		if (*(int *)s->head->content >= min && *(int *)s->head->content < max)
			break ;
		s->head = s->head->next;
	}
	tmp = *i;
	while (tmp++ != s->size)
		s->head = s->head->next;
	tmp = s->size / 2;
	*j = 0;
	while (s->head)
	{
		if (*(int *)s->head->content >= min && *(int *)s->head->content < max)
			*j = tmp;
		s->head = s->head->next;
		tmp++;
	}
	if (*i == (int)(s->size / 2) && *j == 0)
		return(0);
	else
		return (1);
}

void	quick_sort(t_stack *a, t_stack *b)
{
	int 	first;
	int		second;
	int		range;
	int		i;

	i = 0;
	range = a->size / 5;
	while (i++ < 5)
	{
		while (chunk_sort(a, &first, &second, range - (range * i), range * i))
		{
			if (first <= second)
			{
				while (first--)
					exec("ra", a, 0);
			}
			else
			{
				while (second--)
					exec("rra", a, 0);
			}
			exec("pb", a, b);
		}
	}
	printf("stack b:\n");
	printlst(b->head);
	printf("stack b:\n");
	free(b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	while (!search(*a))
	{
		if (*(int *)a->head->content > *(int *)a->head->next->next->content)
			exec("ra", a, b);
		else if (*(int *)a->head->content > *(int *)a->head->next->content)
			exec("sa", a, 0);
		else if (*(int *)a->head->next->content > *(int *)a->head->next->next->content)
			exec("rra", a, 0);




/*		if(search(*a))
			break ;*/
	}
	free(b);
}

void	radix_sort(t_stack *a, t_stack *b)
{


	printf("stack b:\n");
	printlst(b->head);

	free(b);
	return ;
}

