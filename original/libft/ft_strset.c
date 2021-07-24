/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:34:40 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/16 12:34:49 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strset(const char *s, char *set)
{
	while (*set)
	{
		if (ft_strchr(s, *set))
			return (ft_strchr(s, *set));
		set++;
	}
	return (NULL);
}
