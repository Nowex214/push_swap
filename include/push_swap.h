/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:35:35 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/06 16:24:51 by ehenry           ###   ########.fr       */
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
//quickSort
void		quickSort(int *arr, int low, int high);
//parser
int			parsing(int ac, char **av, t_stack *stack);
int			single_argument(char *arg, t_stack *stack);
int			args_duplicate_check(t_stack *stack, int value);
int			invalid_value(char *arg, int *value);
//Check stack
int			is_digit(const char *str);
int			check_atoi(const char *str, int *res_s);
int			duplicate_check(t_stack *stack, int value);
void		add_node(t_stack *stack, int value);
//utils
void		ft_node_swap(t_node *first, t_node *second);
void		free_split(char **split);
int			ft_atoi_custom(const char *str);
//main
t_stack		*init_stack(char id);
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