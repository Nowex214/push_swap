/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:56:00 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/27 10:55:00 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	invalid_value(char *arg, int *value)
{
	long	tmp;

	if (!is_digit(arg))
		return(0);
	tmp = ft_atoi(arg);
	if (tmp < INT_MIN || tmp > INT_MAX)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	*value = (int)tmp;
	return (1);
}

static int	args_duplicate_check(t_stack *stack, int value)
{
	if (duplicate_check(stack, value))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

static int	process_single_argument(char *arg, t_stack *stack)
{
	int		i;
	int		value;
	char	**args;

	args = ft_split(arg, ' ');
	if (!args)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (args[i])
	{
		if (!invalid_value(args[i], &value) || !args_duplicate_check(stack,
				value))
		{
			free_split(args);
			return (0);
		}
		add_node(stack, value);
		i++;
	}
	free_split(args);
	return (1);
}

int	parsing(int ac, char **av, t_stack *stack)
{
	int	i;
	int	value;

	if (ac < 2)
		return (0);
	stack->size = 0;
	i = 1;
	if (ac == 2)
	{
		if (!process_single_argument(av[1], stack))
			return (0);
	}
	else
	{
		while (av[i])
		{
			if (!invalid_value(av[i], &value) || !args_duplicate_check(stack,
					value))
				return (0);
			add_node(stack, value);
			i++;
		}
	}
	return (1);
}
