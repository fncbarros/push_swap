/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:33:43 by fbarros           #+#    #+#             */
/*   Updated: 2021/03/10 17:21:55 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		r;
	size_t	i;

	r = 0;
	i = 0;
	while (i < n && (s1 || s2))
	{
		r = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (r != 0)
			return (r);
		i++;
	}
	return (r);
}
