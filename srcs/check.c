/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:11:34 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/06 13:18:45 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_digit(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_atoi(const char *str, int *res_s)
{
	if (!is_digit(str))
	{
		ft_printf("Error: invalid number '%s\n", str);
		return (0);
	}
	*res_s = ft_atoi_custom(str);
	ft_printf("coverted '%s' to '%d'\n", str, *res_s);
	return (1);
}

int	duplicate_check(t_stack *stack, int value)
{
	t_node	*curr;

	curr = stack->top;
	while (curr)
	{
		ft_printf("compare %d with %d\n", curr->value, value);
		if (curr->value == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	add_node(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return;
	new->value = value;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
	ft_printf("Value add %d\n", new->value);
}