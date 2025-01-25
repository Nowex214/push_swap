/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:35:35 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/25 18:23:59 by ehenry           ###   ########.fr       */
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
	t_node	*top;
}	t_stack;
void		free_stack_on_error(t_stack *stack);
//utils sort
int			partitionA(t_stack *stack_a, t_stack *stack_b, int pivot, int size);
void		pushBackToA(t_stack *stack_a, t_stack *stack_b, int count);
int			findPivot(t_stack *stack_a, int	size);
void		sortArray(int *arr, int	size);
//quicksort
void		quickSort(t_stack *stack_a, t_stack *stack_b, int size);
//parser
int			parsing(int ac, char **av, t_stack *stack);
//Check stack
int			is_digit(const char *str);
int			duplicate_check(t_stack *stack, int value);
void		add_node(t_stack *stack, int value);
//utils
void		ft_node_swap(t_node *first, t_node *second);
void		free_split(char **split);
//main
t_stack		*init_stack(void);
void		free_stack(t_stack *stack);
//swap
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack_a, t_stack *stack_b);
//push
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
//rotate
void		ra(t_stack *stack);
void		rb(t_stack *stack);
//reverse rotate
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack_a, t_stack *stack_b);

#endif