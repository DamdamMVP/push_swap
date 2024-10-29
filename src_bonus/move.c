/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 06:02:19 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/29 03:07:28 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

int	from_to(t_node *from_cur, t_stack *to, bool a_to_b)
{
	t_nodes	nodes;
	int		to_count;

	nodes.from_cur = from_cur;
	nodes.to_cur = to->top;
	to_count = 0;
	while (nodes.to_cur != NULL)
	{
		if (is_greater_than_max(nodes, to, &to_count, a_to_b))
			break ;
		if (is_smaller_than_min(nodes, to, &to_count, a_to_b))
			break ;
		if (is_between_values(nodes, a_to_b))
		{
			to_count++;
			break ;
		}
		nodes.to_cur = nodes.to_cur->next;
		to_count++;
	}
	return (to_count);
}

void	final_rotation(t_stack *a)
{
	t_node	*current;
	int		max_a;
	int		pos;
	int		size;

	max_a = ft_lstmax(a);
	current = a->top;
	pos = 1;
	size = a->size;
	while (current && current->value != max_a)
	{
		current = current->next;
		pos++;
	}
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

void	generate_move(t_stack *a, t_stack *b, t_move move)
{
	while (move.rr-- > 0)
		rr(a, b);
	while (move.rrr-- > 0)
		rrr(a, b);
	while (move.ra-- > 0)
		ra(a);
	while (move.rb-- > 0)
		rb(b);
	while (move.rra-- > 0)
		rra(a);
	while (move.rrb-- > 0)
		rrb(b);
	while (move.pa-- > 0)
		pa(a, b);
	while (move.pb-- > 0)
		pb(a, b);
}

void	conv_move_cost(t_move *move)
{
	int	rr_count;
	int	rrr_count;

	if (move->ra < move->rb)
		rr_count = move->ra;
	else
		rr_count = move->rb;
	if (move->rra < move->rrb)
		rrr_count = move->rra;
	else
		rrr_count = move->rrb;
	move->rr = rr_count;
	move->ra -= rr_count;
	move->rb -= rr_count;
	move->rrr = rrr_count;
	move->rra -= rrr_count;
	move->rrb -= rrr_count;
	move->cost = move->ra + move->rb + move->rra + move->rrb
		+ move->rr + move->rrr + move->pa + move->pb;
}

void	order_a(t_stack *a)
{
	if (a->size != 3)
		return ;
	if (a->top->value > a->top->next->value
		&& a->top->value > a->top->next->next->value)
		ra(a);
	else if (a->top->next->value > a->top->value
		&& a->top->next->value > a->top->next->next->value)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
	a->max = ft_lstmax(a);
	a->min = ft_lstmin(a);
}
