/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:44:28 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/03 18:47:10 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_node_swap(t_node *first, t_node *second)
{
	int	tmp;

	if (!(first || second))
		return;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}