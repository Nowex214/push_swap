/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:05 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/28 12:10:24 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!parsing(ac, av, stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (stack_a->size > 1)
		push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
