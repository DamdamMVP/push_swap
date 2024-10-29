/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 04:22:33 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/26 23:18:47 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *a)
{
	t_node	*current;
	t_node	*prev;

	if (a->size < 2)
		return ;
	current = a->top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	current->next = a->top;
	a->top = current;
}

void	rrb(t_stack *b)
{
	t_node	*current;
	t_node	*prev;

	if (b->size < 2)
		return ;
	current = b->top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	current->next = b->top;
	b->top = current;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
