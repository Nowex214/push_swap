/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:22:52 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/28 12:42:03 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_three_cases(t_stack *stack, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (stack->size < 3)
	{
		if (stack->size == 2 && stack->top->value > stack->top->next->value)
			sa(stack);
		return ;
	}
	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->top->next->next->value;
	sort_three_cases(stack, first, second, third);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	while (stack_a->size > 3)
	{
		min_pos = find_min_pos(stack_a);
		if (min_pos <= stack_a->size / 2)
		{
			while (min_pos-- > 0)
				ra(stack_a);
		}
		else
		{
			while (min_pos++ < stack_a->size)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
