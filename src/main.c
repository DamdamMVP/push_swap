/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:23:16 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/29 02:38:24 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		total_move;

	total_move = 0;
	if (argc == 1)
		return (0);
	if (init_stacks(&a, &b))
		return (1);
	fill_stack_a(a, b, argc, argv);
	if (is_sorted(a))
		return (free_list(a), free_list(b), 0);
	handle_small_cases(a, b, argc);
	if (argc == 5)
	{
		pb(a, b);
		b->max = ft_lstmax(b);
		b->min = ft_lstmin(b);
	}
	else
		push_initial_elements(a, b);
	sort_stacks(a, b, &total_move);
	free_list(a);
	free_list(b);
	return (0);
}
