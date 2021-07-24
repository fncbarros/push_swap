/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:05:21 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/12 14:12:45 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*-----REMOVE------*/
#include <stdio.h>
void printlst(t_list *tmp);
/*-----REMOVE------*/

typedef struct s_stack
{
	t_list	*head;
	ssize_t	size;
}				t_stack;

/*just to save me from the pain of having to write the whole eff'n thing
Can't use it tho :(
# define L_ELEMENT(x) *(int *)x->content
# define T_ELEMENT(x) *(int *)x->head->content
*/
void	display_err(void);
t_stack	*b_init(void);
void	push(t_stack *src, t_stack *dst);
int		search(t_stack s);
void	swap(t_list **lst);
void	rotate(t_stack *stack, char r);
void	exec(char *arg, t_stack *a, t_stack *b);

void	sort_small(t_stack *a, t_stack *b);
void	quick_sort(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif