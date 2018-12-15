/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:32:34 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 18:10:42 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_commands(t_list **stack_a, t_list **stack_b,\
	t_comm *commands_min, t_comm **commandsr)
{
	t_comm *commanda;

	commanda = commands_min;
	while (commanda)
	{
		if (!ft_strcmp(commanda->command, "ra"))
			rotate(stack_a);
		else if (!ft_strcmp(commanda->command, "rb"))
			rotate(stack_b);
		else if (!ft_strcmp(commanda->command, "rr"))
		{
			rotate(stack_a);
			rotate(stack_b);
		}
		else if (!ft_strcmp(commanda->command, "rra"))
			reverse_rotate(stack_a);
		else if (!ft_strcmp(commanda->command, "rrb"))
			reverse_rotate(stack_b);
		else if (!ft_strcmp(commanda->command, "rrr"))
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
		}
		(*commandsr) = ft_comm_add_back(*commandsr, commanda->command);
		commanda = commanda->next;
	}
	push(stack_b, stack_a);
	(*commandsr) = ft_comm_add_back(*commandsr, "pa");
	ft_comm_clean(&commands_min);
}
