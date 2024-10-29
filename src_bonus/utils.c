/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 05:57:55 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/29 03:34:23 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

void	sort_stacks(t_stack *a, t_stack *b, int *total_move)
{
	t_move	lowest_move;
	bool	a_to_b;

	a_to_b = true;
	while (a->size > 3)
	{
		lowest_move = calc_lowest_cost(a, b, a_to_b);
		*total_move += lowest_move.cost;
		generate_move(a, b, lowest_move);
	}
	order_a(a);
	a_to_b = false;
	while (b->size > 0)
	{
		lowest_move = calc_lowest_cost(b, a, a_to_b);
		*total_move += lowest_move.cost;
		generate_move(a, b, lowest_move);
	}
	final_rotation(a);
}

void	fill_stack_a(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		if (!ft_aredigit(argc, argv))
		{
			ft_error("Error\n");
			free_list(a);
			free_list(b);
			exit(EXIT_FAILURE);
		}
		value = ft_atol(argv[argc - i]);
		if (!is_a_int(value) || is_duplicate(a, value))
		{
			ft_error("Error\n");
			free_list(a);
			free_list(b);
			exit(EXIT_FAILURE);
		}
		push(a, (int)value);
		i++;
	}
}

void	handle_small_cases(t_stack *a, t_stack *b, int argc)
{
	if (argc == 2)
	{
		free_list(a);
		free_list(b);
		exit(0);
	}
	if (argc == 3)
	{
		if (a->top->value > a->top->next->value)
			ra(a);
		free_list(a);
		free_list(b);
		exit(0);
	}
	if (argc == 4)
	{
		order_a(a);
		free_list(a);
		free_list(b);
		exit(0);
	}
}

void	push_initial_elements(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	b->max = ft_lstmax(b);
	b->min = ft_lstmin(b);
}

int	more_than_ten_digits(const char *arg)
{
	int	len;

	len = 0;
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg == '0')
		arg++;
	while (*arg >= '0' && *arg <= '9')
	{
		len++;
		arg++;
	}
	if (len > 10)
		return (1);
	return (0);
}
