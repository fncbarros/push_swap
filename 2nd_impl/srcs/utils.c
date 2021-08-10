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

void	display_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	a_search(const int *a, int len)
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

int	_atoi(const char *str)
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
		display_err();
	return (n);
}

int	get_index(int number, int *n, int size, int len)
/*Binary search
int len very stupid idea
Not working at all times*/
{
	int	i;
	(void)size;
	(void)len;

	i = 0;
	while (n[i] != number && i < len)
		i++;
	return (i);
/*	i = size / 2;
	// if (i <= 0)
	// 	return (0);
	if (i >= len)
		return (len - 1);
	if (number != n[i])
	{
		if (number == n[i + 1])
			return (i + 1);
		else if (number == n[i - 1])
			return (i - 1);
		else if (number < n[i])
			return (get_index(number, n, i, len));
		else
			return (get_index(number, n, size + (i + 1), len));
	}
	return (i);
*/}
