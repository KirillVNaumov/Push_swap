/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:42:12 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 13:42:41 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (commands)
	{
		ft_printf("%s\n", commands->command);
		commands = commands->next;
	}
	return (0);
}
