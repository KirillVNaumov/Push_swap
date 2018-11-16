/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:42:12 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 16:36:53 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_right_commnds(t_comm *commands)
{
	while (commands->next)
	{
		if ((!ft_strcmp(commands->command, "ra") &&
		!ft_strcmp(commands->next->command, "rra")) ||
		(!ft_strcmp(commands->command, "rra") &&
		!ft_strcmp(commands->next->command, "ra"))
		|| (!ft_strcmp(commands->command, "pb") &&
		!ft_strcmp(commands->next->command, "pa")) ||
		(!ft_strcmp(commands->command, "pa") &&
		!ft_strcmp(commands->next->command, "pb")) ||
		(!ft_strcmp(commands->command, "rb") &&
		!ft_strcmp(commands->next->command, "rrb"))
		|| (!ft_strcmp(commands->command, "rrb") &&
		!ft_strcmp(commands->next->command, "rb")) ||
		(!ft_strcmp(commands->command, "rra") &&
		!ft_strcmp(commands->next->command, "rrb")) ||
		(!ft_strcmp(commands->command, "rrb")
		&& !ft_strcmp(commands->next->command, "rra")))
			return (0);
		commands = commands->next;
	}
	return (1);
}

int	find_solution(t_list **stack_a, int flag_v, int flag_c)
{
	t_list	*stack_b;
	t_comm	*commands;
	int		stop;

	stop = 0;
	commands = NULL;
	stack_b = NULL;
	*stack_a = list_assign_pos(*stack_a);
	while (1)
	{
		if (solver(stack_a, &stack_b, &commands) == 1)
			stop = 1;
		if (flag_v == 1)
			print_status(*stack_a, stack_b, flag_c);
		if (stop == 1)
			break ;
	}
	while (check_for_right_commnds(commands) == 0)
		commands = optimize_answer(commands);
	while (commands)
	{
		ft_printf("%s\n", commands->command);
		commands = commands->next;
	}
	return (0);
}
