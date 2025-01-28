/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:44:28 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/28 12:40:36 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_node_swap(t_node *first, t_node *second)
{
	int	tmp;

	if (first && second)
	{
		tmp = first->value;
		first->value = second->value;
		second->value = tmp;
	}
}

void	add_node(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
	}
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

int	is_sorted(t_stack *stack, int size)
{
	t_node	*current;
	int		i;

	if (size <= 1)
		return (1);
	current = stack->top;
	i = 0;
	while (current->next && i < size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
