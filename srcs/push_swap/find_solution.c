/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:42:12 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/19 13:09:55 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_last_number(t_list *stack_a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (stack_a)
	{
		tmp = stack_a;
		while (tmp)
		{
			if (i < tmp->pos)
				i = tmp->pos;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (i);
}

int	find_solution(t_list **stack_a)
{
	t_list	*stack_b;
	t_comm	*commands;
	int		end;
	int		stop;

	stop = 0;
	commands = NULL;
	stack_b = NULL;
	*stack_a = list_assign_pos(*stack_a);
	end = find_the_last_number(*stack_a);
	while (1)
		if (solver(stack_a, &stack_b, &commands, end) == 1)
			break ;
	if (!commands)
		return (0);
	while (check_for_right_commnds(commands) == 0)
		commands = optimize_answer(commands);
	while (commands)
	{
		ft_printf("%s\n", commands->command);
		commands = commands->next;
	}
	return (0);
}
