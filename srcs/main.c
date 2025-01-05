/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:05 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/05 16:46:02 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(char id)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->id = id;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*tmp;

	if (!stack)
		return;
	curr = stack->top;
	while (curr)
	{
		tmp = curr->next;
		free (curr);
		curr = tmp;
	}
	free(stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack('A');
	stack_b = init_stack('B');
	if (!(stack_a || stack_b))
	{
		ft_printf("Error: memory allocation failed\n");
		return(1);
	}
	if (!parsing(ac, av, stack_a))
	{
		ft_printf("Error: invalid arguments\n");
		return (1);
	}
	ft_printf("Stacks successfully init and parsed\n");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}