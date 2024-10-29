/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:47:55 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/26 05:21:08 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_move	calc_actual_cost(t_stack_ab ab, int f_count, t_node *f_cur, bool a_to_b)
{
	t_move	act_move;
	int		to_count;

	ft_memset(&act_move, 0, sizeof(t_move));
	act_move.value = f_cur->value;
	to_count = from_to(f_cur, ab.to, a_to_b);
	if (a_to_b)
	{
		set_counts_a_to_b(&act_move, ab, f_count, to_count);
		act_move.pb = 1;
	}
	else
	{
		set_counts_b_to_a(&act_move, ab, f_count, to_count);
		act_move.pa = 1;
	}
	conv_move_cost(&act_move);
	return (act_move);
}

t_move	calc_lowest_cost(t_stack *from, t_stack *to, bool a_to_b)
{
	t_node		*from_cur;
	t_stack_ab	ab;
	t_move		lowest_cost;
	t_move		act_move;
	int			from_count;

	ab.from = from;
	ab.to = to;
	from_cur = from->top;
	from_count = 0;
	lowest_cost.cost = INT_MAX;
	while (from_cur != NULL)
	{
		act_move = calc_actual_cost(ab, from_count, from_cur, a_to_b);
		if (act_move.cost < lowest_cost.cost)
			lowest_cost = act_move;
		from_cur = from_cur->next;
		from_count++;
	}
	if (lowest_cost.value > to->max)
		to->max = lowest_cost.value;
	if (lowest_cost.value < to->min)
		to->min = lowest_cost.value;
	return (lowest_cost);
}

void	set_counts_a_to_b(t_move *act_move, t_stack_ab ab, int f_count,
						int to_count)
{
	if (f_count <= ab.from->size / 2)
		act_move->ra = f_count;
	else
		act_move->rra = ab.from->size - f_count;
	if (to_count <= ab.to->size / 2)
		act_move->rb = to_count;
	else
		act_move->rrb = ab.to->size - to_count;
}

void	set_counts_b_to_a(t_move *act_move, t_stack_ab ab, int f_count,
						int to_count)
{
	if (f_count <= ab.from->size / 2)
		act_move->rb = f_count;
	else
		act_move->rrb = ab.from->size - f_count;
	if (to_count <= ab.to->size / 2)
		act_move->ra = to_count;
	else
		act_move->rra = ab.to->size - to_count;
}
