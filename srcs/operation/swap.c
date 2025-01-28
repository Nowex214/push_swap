/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:03:11 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/28 12:41:01 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	ft_node_swap(first, second);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	ft_node_swap(first, second);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
