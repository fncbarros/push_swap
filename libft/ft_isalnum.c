/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:57:43 by fbarros           #+#    #+#             */
/*   Updated: 2021/03/04 19:51:25 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((58 > c && 47 < c) || (64 < c && 91 > c) || (96 < c && 123 > c))
		return (666);
	else
		return (0);
}
