/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:05 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/24 20:55:24 by ehenry           ###   ########.fr       */
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

int	handle_error(const char *msg, t_stack *stack_a, t_stack *stack_b)
{
	if (msg)
		ft_printf("%s\n", msg);
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
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
		return (handle_error("Error: malloc failed", stack_a, stack_b));
	if (!parsing(ac, av, stack_a))
		return (handle_error("Error: invalid arguments", stack_a, stack_b));
	if (stack_a->size > 1)
		quickSort(stack_a, stack_b, stack_a->size);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
