/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 05:53:01 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/26 05:13:20 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_between_top_and_end(t_stack *a, int value)
{
	t_node	*last;

	last = a->top;
	while (last->next != NULL)
		last = last->next;
	if ((value > last->value && value < a->top->value)
		|| (value == last->value && value != a->top->value)
		|| (value == a->top->value && value != last->value))
		return (1);
	return (0);
}

int	is_greater_than_max(t_nodes cur, t_stack *to, int *to_count, bool a_to_b)
{
	if (cur.from_cur->value > to->max && cur.to_cur->value == to->max)
	{
		if (!a_to_b)
			(*to_count)++;
		return (1);
	}
	return (0);
}

int	is_smaller_than_min(t_nodes cur, t_stack *to, int *to_count, bool a_to_b)
{
	if (cur.from_cur->value < to->min && cur.to_cur->value == to->min)
	{
		if (a_to_b)
			(*to_count)++;
		return (1);
	}
	return (0);
}

int	is_between_values(t_nodes cur, bool a_to_b)
{
	if (a_to_b)
		return (cur.to_cur->value > cur.from_cur->value
			&& (cur.to_cur->next == NULL
				|| cur.to_cur->next->value <= cur.from_cur->value));
	else
		return (cur.to_cur->value < cur.from_cur->value
			&& (cur.to_cur->next == NULL
				|| cur.to_cur->next->value >= cur.from_cur->value));
}
