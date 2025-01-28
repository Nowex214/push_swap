/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:30:03 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/28 12:43:45 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_pivot(t_stack *stack_a, int size)
{
	int		*arr;
	int		i;
	t_node	*curr;
	int		pivot;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	curr = stack_a->top;
	i = 0;
	while (i < size && curr)
	{
		arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
	sort_array(arr, size);
	pivot = arr[size / 2];
	free(arr);
	return (pivot);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	int	max_pos;
	int	size;

	while (stack_b->size > 0)
	{
		max_pos = find_max_pos(stack_b, stack_b->size);
		size = stack_b->size;
		if (max_pos <= size / 2)
		{
			while (max_pos > 0)
			{
				rb(stack_b);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < size)
			{
				rrb(stack_b);
				max_pos++;
			}
		}
		pa(stack_a, stack_b);
	}
}

int	find_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	if (!stack->top)
		return (-1);
	current = stack->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}
