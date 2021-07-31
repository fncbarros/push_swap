/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:33:02 by fbarros           #+#    #+#             */
/*   Updated: 2021/07/27 23:33:05 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*Best to copy outside function and merge list itself instead of allocating memory
	Need to break into more functions*/

int	*merge(int *left, int *right, int q)
{
	int	results[q * 2];
	int	i;

	i = 0;
	while (results[i])
	{
		if (*left < *right)
			results[i++] = *left++;
		else
			results[i++] = *right++;
	}
	return (results);
}

void	merge_sort(const int *a, int len, int *copy) //Not sure copy would work with recursion; 
{
	int	q;

	q = len / 2; // middle
	if ((sizeof(a) / sizeof(a[0]) < len)) //base case
		return ; //return (results); (??)
	merge_sort(a, q - 1, copy); //DIVIDE LEFT SIDE
	merge_sort(a[q], q, copy); //DIVIDE RIGHT SIDE
	copy = merge(a, a[q], q);
//	return (copy); //MERGE BOTH SIDES (malloc and return results or return a)
}

int main(void)
{
	int array[] = {5, 3, 4, 1, 9, 6, 0, 2}; //TEST ODD NUMBERS
	int len = sizeof(array) / sizeof(array[0]);
	int copy[len];
	int	i = -1;

	merge_sort(array, len, copy);
	while (++i < len)
		printf("%d\t", array[i]);
}