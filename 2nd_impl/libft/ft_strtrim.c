/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:23:47 by fbarros           #+#    #+#             */
/*   Updated: 2021/03/12 17:51:22 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		start;
	int		end;
	char	*s2;

	if (!s1)
		return (NULL);
	start = 0;
	while (*s1 && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	len = (end - start) + 2;
	if (end <= start)
		len = 1;
	s2 = (char *)malloc(len);
	if (!s2)
		return (NULL);
	len = 0;
	while (start <= end)
		s2[len++] = s1[start++];
	s2[len] = '\0';
	return (s2);
}
