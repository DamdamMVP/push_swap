/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:57:01 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/29 02:39:43 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_aredigit(int argc, char **argv)
{
	char	*arg;
	int		i;

	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		if (*arg == '-' || *arg == '+')
			arg++;
		if (*arg == '\0')
			return (0);
		while (*arg)
		{
			if (!ft_isdigit(*arg))
				return (0);
			arg++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (a == NULL || a->top == NULL)
		return (1);
	current = a->top;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_duplicate(t_stack *a, int value)
{
	t_node	*current;

	current = a->top;
	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_a_int(long value)
{
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	return (1);
}
