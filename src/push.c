/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 04:22:00 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/24 22:21:03 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	ft_printf("pa\n");
	if (b->top == NULL)
		return ;
	temp = b->top;
	b->top = b->top->next;
	temp->next = a->top;
	a->top = temp;
	a->size++;
	b->size--;
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	ft_printf("pb\n");
	if (a->top == NULL)
		return ;
	temp = a->top;
	a->top = a->top->next;
	temp->next = b->top;
	b->top = temp;
	b->size++;
	a->size--;
}
