/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:59:12 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/27 09:42:50 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	quick_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	pivot;
	int	low;
	int	high;

	if (size < 2)
		return ;
	if (stack_a->size < size)
		size = stack_a->size;
	if (size < 2)
		return ;
	pivot = find_pivot(stack_a, size);
	low = partition_a(stack_a, stack_b, pivot, size);
	high = size - low;
	if (low == 0 || low == size)
		return ;
	quick_sort(stack_a, stack_b, high);
	push_back_to_a(stack_a, stack_b, low);
	quick_sort(stack_a, stack_b, low);
}
