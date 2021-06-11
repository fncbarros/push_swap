/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 12:06:46 by fbarros           #+#    #+#             */
/*   Updated: 2021/03/05 20:00:16 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hst, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	if (*ndl == '\0')
		return ((char *)hst);
	i = 0;
	while (*(hst + i) != '\0' && i < len)
	{
		j = 0;
		while (hst[i + j] == ndl[j] && ndl[j] && (i + j) < len)
		{
			if (ndl[j + 1] == '\0')
				return ((char *)hst + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
