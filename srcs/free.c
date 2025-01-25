/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:59:13 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/25 18:39:20 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void free_stack(t_stack *stack)
{
    t_node *curr;
    t_node *tmp;

    if (!stack)
        return;
    curr = stack->top;
    while (curr)
    {
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(stack);
}
