/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:37:37 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/28 12:51:48 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (11);
	return (13);
}

static void	process_remaining_elements(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 0)
	{
		pb(stack_a, stack_b);
	}
}

static void	process_chunk(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int	distance;

	while (find_next_in_chunk(stack_a, min, max) != -1)
	{
		if (stack_a->top->value >= min && stack_a->top->value < max)
		{
			pb(stack_a, stack_b);
			if (stack_b->size > 1 && stack_b->top->value < (max + min) / 2)
				rb(stack_b);
		}
		else
		{
			distance = find_next_in_chunk(stack_a, min, max);
			if (distance > stack_a->size / 2)
				rra(stack_a);
			else
				ra(stack_a);
		}
	}
}

static void	handle_chunk(t_stack *stack_a, t_stack *stack_b, int *limits,
		int chunk_count)
{
	int	chunk_min;
	int	chunk_max;
	int	i;

	i = -1;
	while (++i < chunk_count)
	{
		chunk_min = limits[0] + (i * ((limits[1] - limits[0]) / chunk_count));
		chunk_max = limits[0] + ((i + 1) * ((limits[1] - limits[0])
					/ chunk_count));
		process_chunk(stack_a, stack_b, chunk_min, chunk_max);
	}
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	limits[2];
	int	chunk_count;

	chunk_count = get_chunk_count(stack_a->size);
	limits[0] = get_min(stack_a);
	limits[1] = get_max(stack_a);
	handle_chunk(stack_a, stack_b, limits, chunk_count);
	process_remaining_elements(stack_a, stack_b);
	push_back(stack_a, stack_b);
}
