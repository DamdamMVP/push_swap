/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 04:22:33 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/22 20:23:18 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, bool both)
{
	t_node	*current;
	t_node	*prev;

	if (both == false)
		ft_printf("rra\n");
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

void	rrb(t_stack *b, bool both)
{
	t_node	*current;
	t_node	*prev;

	if (both == false)
		ft_printf("rrb\n");
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
	ft_printf("rrr\n");
	rra(a, true);
	rrb(b, true);
}
