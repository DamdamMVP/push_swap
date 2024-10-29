/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:44:41 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/29 03:30:43 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "libft.h"

// struct
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_nodes
{
	t_node	*from_cur;
	t_node	*to_cur;
}	t_nodes;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	int		max;
	int		min;
}	t_stack;

typedef struct s_stack_ab
{
	t_stack	*from;
	t_stack	*to;
}	t_stack_ab;

typedef struct s_move
{
	int	rr;
	int	rrr;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	pa;
	int	pb;
	int	cost;
	int	value;
}	t_move;

// cost_calc
t_move	calc_lowest_cost(t_stack *from, t_stack *to, bool a_to_b);
t_move	calc_actual_cost(t_stack_ab ab, int f_count, t_node *f_cur,
			bool a_to_b);
void	set_counts_a_to_b(t_move *act_move, t_stack_ab ab, int f_count,
			int to_count);
void	set_counts_b_to_a(t_move *act_move, t_stack_ab ab, int f_count,
			int to_count);

// is_functions.c
int		is_between_top_and_end(t_stack *a, int value);
int		is_greater_than_max(t_nodes cur, t_stack *to, int *to_count,
			bool a_to_b);
int		is_smaller_than_min(t_nodes cur, t_stack *to, int *to_count,
			bool a_to_b);
int		is_between_values(t_nodes cur, bool a_to_b);
int		is_last_element(t_nodes cur, t_stack *to,
			int to_count, bool a_to_b);

// is_functions2.c
int		ft_aredigit(int argc, char **argv);
int		is_sorted(t_stack *a);
int		is_duplicate(t_stack *a, int value);
int		is_a_int(long value);

// move.c
int		from_to(t_node *from_cur, t_stack *to, bool a_to_b);
void	final_rotation(t_stack *a);
void	generate_move(t_stack *a, t_stack *b, t_move move);
void	conv_move_cost(t_move *move);
void	order_a(t_stack *a);

// stack_init.c
t_stack	*init_stack(void);
int		init_stacks(t_stack **a, t_stack **b);
void	push(t_stack *stack, int value);
t_node	*get_last_node(t_stack *stack);

// stack_utils.c
void	free_list(t_stack *stack);
void	print_list(t_node *head);
int		ft_lstmax(t_stack *stack);
int		ft_lstmin(t_stack *stack);
void	ft_error(const char *message);

// utlis.c
void	sort_stacks(t_stack *a, t_stack *b, int *total_move);
void	fill_stack_a(t_stack *a, t_stack *b, int argc, char **argv);
void	handle_small_cases(t_stack *a, t_stack *b, int argc);
void	push_initial_elements(t_stack *a, t_stack *b);
int		more_than_ten_digits(const char *arg);

// push
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// swap
void	sa(t_stack *a, bool both);
void	sb(t_stack *b, bool both);
void	ss(t_stack *a, t_stack *b);

// rotate
void	ra(t_stack *a, bool both);
void	rb(t_stack *b, bool both);
void	rr(t_stack *a, t_stack *b);

// reverse_rotate
void	rra(t_stack *a, bool both);
void	rrb(t_stack *b, bool both);
void	rrr(t_stack *a, t_stack *b);

// main
int		exec_instruction(char *line, t_stack *a, t_stack *b);