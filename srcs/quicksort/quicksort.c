/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:59:12 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/24 20:38:54 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	quickSort(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	pivot;
	int	low;
	int	high;

	if (size < 2)
		return;
	if (stack_a->size < size)
		size = stack_a->size;
	if (size < 2)
		return;
	pivot = findPivot(stack_a, size);
	low = partitionA(stack_a, stack_b, pivot, size);
	high = size - low;
	if (low == 0 || low == size)
		return;
	quickSort(stack_a, stack_b, high);
	pushBackToA(stack_a, stack_b, low);
	quickSort(stack_a, stack_b, low);
}

