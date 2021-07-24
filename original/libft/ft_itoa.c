/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:05:49 by fbarros           #+#    #+#             */
/*   Updated: 2021/04/18 17:49:18 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (0 == n)
		return (1);
	if (0 > n)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static long int	ft_intrev(int n)
{
	long int	rev;

	rev = 0;
	while (n != 0)
	{
		rev *= 10;
		rev += n % 10;
		n /= 10;
	}
	if (0 > rev)
		rev *= -1;
	return (rev);
}

char	*ft_itoa(int n)
{
	long int	rev;
	size_t		len;
	size_t		i;
	char		*s;

	len = ft_intlen(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	rev = ft_intrev(n);
	i = 0;
	if (n < 0)
	{
		i = 1;
		s[0] = '-';
	}
	while (i < len)
	{
		n = rev % 10;
		s[i++] = n + 48;
		rev /= 10;
	}
	s[i] = '\0';
	return (s);
}