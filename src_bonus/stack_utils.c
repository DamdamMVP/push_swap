/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:17:10 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/26 23:18:27 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "push_swap_bonus.h"

void	free_list(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	current = stack->top;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(stack);
}

void	print_list(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d -> ", current->value);
		current = current->next;
	}
	ft_printf("NULL\n");
}

int	ft_lstmax(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (stack == NULL || stack->top == NULL)
		return (INT_MIN);
	current = stack->top;
	max = current->value;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	ft_lstmin(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (stack == NULL || stack->top == NULL)
		return (INT_MAX);
	current = stack->top;
	min = current->value;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

void	ft_error(const char *message)
{
	if (message)
		write(2, message, ft_strlen(message));
}
