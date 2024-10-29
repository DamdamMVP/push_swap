/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 04:22:12 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/26 23:18:12 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*current;

	if (a->size < 2)
		return ;
	first = a->top;
	a->top = a->top->next;
	first->next = NULL;
	current = a->top;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*current;

	if (b->size < 2)
		return ;
	first = b->top;
	b->top = b->top->next;
	first->next = NULL;
	current = b->top;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
