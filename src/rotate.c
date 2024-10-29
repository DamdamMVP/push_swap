/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 04:22:12 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/24 22:20:50 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, bool both)
{
	t_node	*first;
	t_node	*current;

	if (both == false)
		ft_printf("ra\n");
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

void	rb(t_stack *b, bool both)
{
	t_node	*first;
	t_node	*current;

	if (both == false)
		ft_printf("rb\n");
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
	ft_printf("rr\n");
	ra(a, true);
	rb(b, true);
}
