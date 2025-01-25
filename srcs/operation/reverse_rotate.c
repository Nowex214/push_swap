/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:03:11 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/25 18:11:03 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || stack->size < 2)
		return;
	second_last = stack->top;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
	write (1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	rra(stack);
	write (1, "rrb\n", 4);
}


void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write (1, "rrr\n", 4);
}
