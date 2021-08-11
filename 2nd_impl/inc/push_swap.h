/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:05:21 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/04 22:52:18 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

# define SHORT_LST 10

typedef struct s_dlist
{
	int				n;
	int				index;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

typedef struct s_stack
{
	t_dlist	*head;
	int		size;
	t_dlist	*last;
	int		neg;
	int		*arr;
}	t_stack;

void	display_err(t_stack *s);
void	*malloc_n_check(size_t block, t_stack *s);
void	push(t_stack *src, t_stack *dst);
int		a_search(int *a, int len);
int		s_search(t_stack s);
void	swap(t_stack *s);
void	rotate(t_stack *s, char r);
void	exec(char *arg, t_stack *a, t_stack *b);
void	sort_array(int *lst, int len);
int		_atoi(const char *str, t_stack *s);
int		get_index(int number, int *n, int len);

t_dlist	*lstnew(int content, t_stack *s);
t_dlist	*lstlast(t_dlist *lst);
void	lstclear(t_dlist **lst);
void	lstadd_front(t_stack *s, t_dlist *new_elmt);

void	sort_small(t_stack *a, t_stack *b);
void	quicksort(int *a, int l, int r);
void	radix_sort(t_stack *a, t_stack *b);

#endif
