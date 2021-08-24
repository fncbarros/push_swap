/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:08:25 by fbarros           #+#    #+#             */
/*   Updated: 2021/03/12 19:50:20 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	j;
	int	neg;

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
	return (n * neg);
}
