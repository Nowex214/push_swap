/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:06:08 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/28 12:48:55 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_max_pos(t_stack *stack_b, int count)
{
	int		i;
	int		max_pos;
	int		max;
	t_node	*current;

	max = INT_MIN;
	max_pos = -1;
	i = 0;
	current = stack_b->top;
	while (i < count)
	{
		if (current->value > max)
		{
			max = current->value;
			max_pos = i;
		}
		current = current->next;
		i++;
	}
	return (max_pos);
}

void	push_back_to_a(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	max_pos;

	while (count > 0)
	{
		max_pos = find_max_pos(stack_b, count);
		while (max_pos > 0)
		{
			rb(stack_b);
			max_pos--;
		}
		pa(stack_a, stack_b);
		count--;
	}
}

int	get_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack->top)
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_next_in_chunk(t_stack *stack, int chunk_min, int chunk_max)
{
	t_node	*current;
	int		distance;

	current = stack->top;
	distance = 0;
	while (current)
	{
		if (current->value >= chunk_min && current->value < chunk_max)
			return (distance);
		distance++;
		current = current->next;
	}
	return (-1);
}
