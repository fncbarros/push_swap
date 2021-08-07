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
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	copy(const int *original, int *left, int *right, t_indexes *id)
{
	int	len;
	int	i;

	len = id->llen + id->rlen;
	i = -1;
	id->r = -1;
	while (++i < id->llen)
		left[i] = original[i];
	while (i < len)
		right[++id->r] = original[i++];
	id->r = 0;
	id->l = 0;
}

static void	merge(int *a, int l, int h, int m) //no actual need for m here
{
	int			left[(m - l)]; //not permitted
	int			right[(h - m)]; //not permitted
	t_indexes	id;

	id.llen = m - l;
	id.rlen = h - m;
	copy(a, left, right, &id);
	while (id.l < id.llen && id.r < id.rlen)
	{
		if (left[id.l] < right[id.r])
			a[l++] = left[id.l++];
		else
			a[l++] = right[id.r++];
	}
	while (id.l < id.llen)
		a[l++] = left[id.l++];
	while (id.r < id.rlen)
		a[l++] = right[id.r++];
}

void	merge_sort(int *a, int l, int h) //Not sure copy would work with recursion;
{
	int	m;

	m = h / 2; // middle
	if (h > 1) //base case
	{
		merge_sort(a, l, m); //DIVIDE LEFT SIDE
		merge_sort(a + m, m + 1, h); //DIVIDE RIGHT SIDE
		merge(a, l, h, m); //pass tmp[] instead of m maybe
	}
//	return (copy); //MERGE BOTH SIDES (malloc and return results or return a)
}

static int	part(int *a, int l, int r)
{
	int	pivot;
	int	i;
	int	j;

	pivot = a[r];
	i = l - 1;
	j = i;
	while (++j < r)
	{
		if (a[j] < pivot)
		{
			i++;
			ft_swap(a + i, a + j);
		}
	}
	ft_swap(a + (i + 1), a + r);
	return (i + 1);
}

void	quicksort(int *a, int l, int r)
/*--------------NOT YET TESTED------------*/
{
	int	i; //or int *i??

	i = 0;
	if (l > r - 1)
		return ;
	i = part(a, l, r);
	quicksort(a, l, i - 1);
	quicksort(a, i + 1, r);
	/*^----??----^*/
}
/*
int main(void)
{
	int array[] = {6, 5, 4, 3, 2 ,1}; //TEST ODD NUMBERS
	int len = sizeof(array) / sizeof(array[0]);
	int	i = -1;

	while (++i < len)
		printf("%d\t", array[i]);
	//merge_sort(array, 0, len);
	quicksort(array, 0, len); //or len - 1
	i = -1;
	printf("\nAfter merge: \nlen = %d\n", len);
	while (++i <= len)
		printf("i%d\t%d\n", i, array[i]);
}
*/