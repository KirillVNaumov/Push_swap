/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:42:12 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 18:53:00 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_solution(t_list **stack_a)
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
