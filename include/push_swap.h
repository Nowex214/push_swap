/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:35:35 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/03 19:30:57 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

//struct
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct	s_stack
{
	int		size;
	char	id;
	t_node	*top;
}	t_stack;

//utils
void		ft_node_swap(t_node *first, t_node *second);
//swap
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack_a, t_stack *stack_b);
//push
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
#endif