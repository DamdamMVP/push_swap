/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:23:16 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/29 02:40:42 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

int	exec_instruction(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	process_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	line = ft_get_next_line(0);
	while (line != NULL)
	{
		if (!exec_instruction(line, a, b))
		{
			ft_error("Error\n");
			free(line);
			free_list(a);
			free_list(b);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = ft_get_next_line(0);
	}
}

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
	process_instructions(a, b);
	if (is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(a);
	free_list(b);
	return (0);
}
