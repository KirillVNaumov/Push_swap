/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:47:56 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/14 16:27:03 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_solution(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*temp;
	t_comm	*commands;
	int		beginning_chain;

	stack_b = NULL;
	commands = NULL;
	*stack_a = list_assign_pos(*stack_a);
	temp = ft_list_dup(*stack_a);
	beginning_chain = find_the_biggest_chain(temp);
	define_biggest_chain(stack_a, beginning_chain);
	push_b_but_chain(stack_a, &stack_b, &commands);
	while (stack_b != NULL)
		find_and_apply_minimal_oper(stack_a, &stack_b, &commands);
	if (count_rotate(*stack_a, 1) < count_reverse_rotate(*stack_a, 1))
		while ((*stack_a)->pos != 1)
		{
			commands = ft_comm_add_back(commands, "ra");
			rotate(stack_a);
		}
	else
		while ((*stack_a)->pos != 1)
		{
			commands = ft_comm_add_back(commands, "rra");
			reverse_rotate(stack_a);
		}
	while (commands)
	{
		ft_printf("%s\n", commands->command);
		commands = commands->next;
	}
	return (0);
}
