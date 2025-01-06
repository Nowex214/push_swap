/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:56:00 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/06 13:26:34 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	invalid_value(char *arg, int *value)
{
	if (!check_atoi(arg, value))
	{
		ft_printf("Error: invalid value '%s'\n", arg);
		return (0);
	}
	return (1);
}

int	args_duplicate_check(t_stack *stack, int value)
{
	if (duplicate_check(stack, value))
	{
		ft_printf("Error: duplicate value '%d'\n", value);
		return (0);
	}
	return (1);
}

int	single_argument(char *arg, t_stack *stack)
{
	int		i;
	int		value;
	char	**args;

	value = 0;
	i = 0;
	args = ft_split(arg, 32);
	if (!args)
	{
		ft_printf("Error: allocation failed\n");
		return (0);
	}
	while (args[i])
	{
		if (!invalid_value(args[i], &value) || !args_duplicate_check(stack, value))
		{
			free_split(args);
			return (0);
		}
		add_node(stack, value);
		ft_printf("add value single arg '%d'\n", value);
		i++;
	}
	free_split(args);
	return (1);
}

int	parsing(int ac, char **av, t_stack *stack)
{
	int	i;
	int	value;

	value = 0;
	i = 1;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (!single_argument(av[1], stack))
			return (0);
	}
	else
	{
		while (av[i])
		{
			if (!invalid_value(av[i], &value) || !args_duplicate_check(stack, value))
				return (0);
			ft_printf("add value parsing '%d'\n", value);
			add_node(stack, value);
			i++;
		}
	}
	return (1);
}
