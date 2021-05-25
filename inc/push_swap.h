/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:05:21 by fbarros           #+#    #+#             */
/*   Updated: 2021/05/25 12:57:20 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_stack
{
	t_list	*head;
	ssize_t	size;
}				t_stack;

typedef struct s_dlist
{
	int				n;
	struct s_nlist	*up;
	struct s_nlist	*low;
}				t_dlist;

void	display_err(void);
void	push(t_stack *src, t_stack *dst);
int	search(t_stack s);
void	swap(t_list **lst);
void	rotate(t_list **lst, char r);
void	exec(char *arg, t_stack *a, t_stack *b);

#endif
