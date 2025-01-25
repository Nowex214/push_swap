/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:44:28 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/25 18:18:36 by ehenry           ###   ########.fr       */
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

void add_node(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}
