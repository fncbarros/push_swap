/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:55 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/19 13:23:36 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int	main(int argc, char **argv)
{
	int		n;
	t_stack	a;
	t_list	*new;
	int		i;

	a.head = ft_lstnew(argv[1]);
	i = 1;
	while (++i < argc)
		ft_lstadd_back(&(a.head), ft_lstnew(argv[i]));
	a.size = argc - 1;
	new = a.head;
	while (new->next)
	{
		n = ft_atoi((char *)new->content);
		ft_putnbr_fd(n, 1);
		ft_putchar_fd('\n', 1);
		new = new->next;
	}
	n = ft_atoi((char *)new->content);
	ft_putnbr_fd(n, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_lstsize(a.head), 1);
//	ft_lstclear(&a, (free)(void *)); //review function pointers
	return (0);
}
