/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:15:22 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/04 23:03:01 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	a_search(int *a, int len)
{
	int	i;

	if (!a)
		return (0);
	i = 1;
	while (i < len)
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	free(a);
	return (i);
}

int	s_search(t_stack s)
/* searches stack or array
...or int search(t_stack *s)??
 * return 0 if out of order
 *if s.head->next != NULL
 **/
{
	ssize_t	i;

	if (!s.head)
		return (0);
	i = 1;
	while (s.head->next && s.head->n < s.head->next->n)
	{
		s.head = s.head->next;
		i++;
	}
	if (s.size != i)
		return (0);
	else
		return (i);
}

int	_atoi(const char *str, t_stack *s)
{
	long int	n;
	int			j;
	int			neg;

	neg = 1;
	j = 0;
	n = 0;
	while (32 == str[j] || (8 < str[j] && 14 > str[j]))
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			neg = -1;
		j++;
	}
	while (ft_isdigit(str[j]) && str[j])
	{
		n *= 10;
		n += str[j++] - '0';
	}
	n *= neg;
	if (n > INT_MAX || n < INT_MIN)
		display_err(s);
	return (n);
}

int	get_index(int number, int *n, int len)
{
	int	i;

	i = 0;
	while (n[i] != number && i < len)
		i++;
	return (i);
}
