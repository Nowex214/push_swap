/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   y: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:14:05 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/03 19:25:38 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (!stack_b || stack_b->size == 0)
		return;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	tmp->next = stack_a->top;
	stack_a->top = tmp;
	stack_b->size--;
	stack_a->size++;
	write (1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (!stack_a || stack_a->size == 0)
		return;
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	tmp->next = stack_b->top;
	stack_b->top = tmp;
	stack_a->size--;
	stack_b->size++;
	write (1, "pb\n", 3);
}
