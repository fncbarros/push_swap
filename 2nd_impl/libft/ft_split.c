/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:24:04 by fbarros           #+#    #+#             */
/*   Updated: 2021/04/18 18:03:57 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_error(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static size_t	ft_strnum(char const *s, char c)
{
	unsigned int	i;
	size_t			n;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		n++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (n);
}

static size_t	ft_nxt_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	size_t			sn;
	size_t			len;
	char			**arr;

	sn = ft_strnum(s, c);
	arr = (char **)malloc(sizeof(char *) * (sn + 1));
	if (!arr)
		return (NULL);
	len = 0;
	j = 0;
	i = 0;
	while (i < sn && s[j])
	{
		j += len;
		while (s[j] && s[j] == c)
			j++;
		len = ft_nxt_strlen(&s[j], c);
		arr[i] = ft_substr(s, j, len);
		if (arr[i++] == NULL)
			return (ft_error(arr));
	}
	arr[i] = NULL;
	return (arr);
}
