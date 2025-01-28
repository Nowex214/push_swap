/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:59:12 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/28 12:38:40 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size <= 1)
		return ;
	if (stack_a->size <= 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else
		chunk_sort(stack_a, stack_b);
}
