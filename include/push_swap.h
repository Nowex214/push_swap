/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:35:35 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/28 12:49:05 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// struct
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*top;
}					t_stack;
// sort
void				sort_three(t_stack *stack);
void				sort_five(t_stack *stack_a, t_stack *stack_b);
// utils sort
int					find_next_in_chunk(t_stack *stack, int chunk_min,
						int chunk_max);
void				push_back_to_a(t_stack *stack_a, t_stack *stack_b,
						int count);
int					find_pivot(t_stack *stack_a, int size);
int					find_pivot(t_stack *stack_a, int size);
void				sort_array(int *arr, int size);
void				push_back(t_stack *stack_a, t_stack *stack_b);
int					find_min_pos(t_stack *stack);
int					find_max_pos(t_stack *stack_b, int count);
int					find_next_in_chunk(t_stack *stack, int chunk_min,
						int chunk_max);
int					get_max(t_stack *stack);
int					get_min(t_stack *stack);
// quicksort
void				chunk_sort(t_stack *stack_a, t_stack *stack_b);
void				push_swap(t_stack *stack_a, t_stack *stack_b);
// parser
int					parsing(int ac, char **av, t_stack *stack);
// Check stack
int					is_digit(const char *str);
int					duplicate_check(t_stack *stack, int value);
void				add_node(t_stack *stack, int value);
// utils
void				ft_node_swap(t_node *first, t_node *second);
void				free_split(char **split);
int					is_sorted(t_stack *stack, int size);
// main
t_stack				*init_stack(void);
void				free_stack(t_stack *stack);
// swap
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack_a, t_stack *stack_b);
// push
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
// rotate
void				ra(t_stack *stack);
void				rb(t_stack *stack);
// reverse rotate
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack_a, t_stack *stack_b);

#endif