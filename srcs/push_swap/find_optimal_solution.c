/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:04:35 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/19 13:28:15 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_optimal_solution(t_list *stack_a, int flag_optimized)
{
	int			set_depth;
	t_comm		*command_list;
	t_list		*stack_b;

	set_depth = 1;
	command_list = NULL;
	stack_b = NULL;
	while (search(stack_a, stack_b, set_depth, &command_list) == -1)
	{
		set_depth++;
		if (flag_optimized == 0 && set_depth == 7)
			return (0);
		command_list = NULL;
		stack_b = NULL;
	}
	while (command_list)
	{
		ft_printf("%s\n", command_list->command);
		command_list = command_list->next;
	}
	return (1);
}
