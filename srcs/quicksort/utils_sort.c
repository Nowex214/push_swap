/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:06:08 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/24 21:20:06 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	partitionA(t_stack *stack_a, t_stack *stack_b, int pivot, int size)
{
	int	i;
	int	low;

	i = 0;
	low = 0;
	while (i < size && stack_a->top != NULL)
	{
		if (stack_a->top->value < pivot)
		{
			pb(stack_a, stack_b);
			low++;
		}
		else
			ra(stack_a);
		i++;
	}
	return (low);
}

void	pushBackToA(t_stack *stack_a, t_stack *stack_b, int count)
{
	while (count > 0)
	{
		pa(stack_a, stack_b);
		count--;
	}
}

int	findPivot(t_stack *stack_a, int size)
{
	int		*tmp;
	int		i;
	t_node	*curr;
	int		pivot;

	i = 0; 
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	curr = stack_a->top;
	while (i < size && curr != NULL)
	{
		tmp[i] = curr->value;
		curr = curr->next;
		i++;
	}
	sortArray(tmp, i);
	pivot = tmp[i / 2];
	free(tmp);
	return (pivot);
}

void	sortArray(int *arr, int	size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < size)
	{
		tmp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
		i++;
	}
}
