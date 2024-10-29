/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 05:36:15 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/26 01:11:45 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <limits.h>

int	init_stacks(t_stack **a, t_stack **b)
{
	*a = init_stack();
	*b = init_stack();
	if (!(*a) || !(*b))
	{
		ft_error("Error\n");
		return (1);
	}
	return (0);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	stack->max = INT_MIN;
	stack->min = INT_MAX;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

t_node	*get_last_node(t_stack *stack)
{
	t_node	*last;

	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
