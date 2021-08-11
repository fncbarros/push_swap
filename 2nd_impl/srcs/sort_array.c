/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:33:02 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/27 23:33:05 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	if (!a || !b)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	part(int *a, int l, int r)
{
	int	*pivot;
	int	i;
	int	j;

	pivot = &a[r];
	i = l - 1;
	j = i;
	while (++j < r)
	{
		if (a[j] < *pivot)
		{
			i++;
			ft_swap(a + i, a + j);
		}
	}
	ft_swap(a + (i + 1), pivot);
	return (i + 1);
}

void	quicksort(int *a, int l, int r)
{
	int	i;

	i = 0;
	r--;
	if (l > r)
		return ;
	i = part(a, l, r);
	quicksort(a, l, i);
	quicksort(a, i + 1, r + 1);
}

/*
int main(void)
{
	int array[] = {9, -8, 7, -6, 5, 99, -4, 3, 0, 2, 1, 90001, 11}; //TEST ODD NUMBERS
	int len = sizeof(array) / sizeof(array[0]);
	int	i = -1;

	while (++i < len)
		printf("%d\t", array[i]);
//	merge_sort(array, 0, len);
	quicksort(array, 0, len); //or len - 1
	i = -1;
	printf("\nAfter merge: \nlen = %d\n", len);
	while (++i < len)
		printf("i%d\t%d\n",  i , array[i]);
}
*/
