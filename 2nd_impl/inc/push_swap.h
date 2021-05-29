/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:05:21 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/29 17:50:41 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_stacks
{
	t_list	*a;
	t_list	*b
	ssize_t	alen;
	ssize_t	blen;
}				t_stacks;

typedef struct s_dlist
{
	int				n;
	struct s_nlist	*up;
	struct s_nlist	*low;
}				t_dlist;

void	display_err(void);
void	push(t_stacks *s);
int		search(t_stack s);
void	swap(t_list **lst);
void	rotate(t_list **lst, char r);
void	exec(char *arg, t_stacks *s);
void	quick_sort(t_stack *a);

#endif
