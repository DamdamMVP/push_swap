/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 04:21:51 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/26 23:18:31 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
