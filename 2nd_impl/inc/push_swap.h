/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:05:21 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/12 15:55:14 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h> /*INT_MAX INT_MIN*/


/*-------->(2 stacks in 1 struct maybe not good idea)<-------*/
typedef struct	s_stack
{
	t_lst	*a;
	t_lst	*b;
	ssize_t	alen;
	ssize_t	blen;
}				t_stack;

/*not using for now*/
typedef struct	s_dlist
{
	int		num;
	struct s_nlist	*up;
	struct s_nlist	*low;
}		t_dlist;

void	display_err(void);
void	push(t_stack *s, char c);
int		search(t_stack s, char c);
void	swap(t_lst **lst);
void	rotate(t_lst **lst, char r);
void	exec(char *arg, t_stack *s);
void	quick_sort(t_stack *a);

#endif
