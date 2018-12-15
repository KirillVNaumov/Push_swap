/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:32:34 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 17:52:56 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_commands(t_list **stack_a, t_list **stack_b,\
	t_comm *commands_min, t_comm **commandsr)
{
	while (commands_min)
	{
		if (!ft_strcmp(commands_min->command, "ra"))
			rotate(stack_a);
		else if (!ft_strcmp(commands_min->command, "rb"))
			rotate(stack_b);
		else if (!ft_strcmp(commands_min->command, "rr"))
		{
			rotate(stack_a);
			rotate(stack_b);
		}
		else if (!ft_strcmp(commands_min->command, "rra"))
			reverse_rotate(stack_a);
		else if (!ft_strcmp(commands_min->command, "rrb"))
			reverse_rotate(stack_b);
		else if (!ft_strcmp(commands_min->command, "rrr"))
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
		}
		(*commandsr) = ft_comm_add_back(*commandsr, commands_min->command);
		commands_min = commands_min->next;
	}
	push(stack_b, stack_a);
	(*commandsr) = ft_comm_add_back(*commandsr, "pa");
}
