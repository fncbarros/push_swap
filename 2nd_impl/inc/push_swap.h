/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:05:21 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/23 10:08:15 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_dlist
{
	int				n;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}				t_dlist;

typedef struct s_stack
{
	t_dlist	*head;
	int		size;	//ssize_t
}				t_stack;

/*-----REMOVE------*/
#include <stdio.h>
void printlst(t_dlist *tmp);
/*-----REMOVE------*/

void	display_err(void);
t_stack	*b_init(void);
void	push(t_stack *src, t_stack *dst);
int		search(t_stack s);
void	swap(t_dlist **lst);
void	rotate(t_dlist **lst, char r);
void	exec(char *arg, t_stack *a, t_stack *b);
int		find_closest(t_stack *a, int mod, int dec);

t_dlist	*lstnew(int content);
t_dlist	*lstlast(t_dlist *lst);
//void	lstdelone(t_dlist *lst, void (*del)(int)); //may be useless
void	lstclear(t_dlist **lst/*, void (*del)(int)*/); //may be useless
void	lstadd_front(t_dlist **lst, t_dlist *new_elmt);

void	sort_small(t_stack *a, t_stack *b);
void	quick_sort(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif
