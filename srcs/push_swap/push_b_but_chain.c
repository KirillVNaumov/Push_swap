/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_but_chain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:18:19 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 17:53:34 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_but_chain(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	int	ra;

	ra = find_number_of_zero_chain(*stack_a);
	while ((*stack_a)->if_chain == 0 && ra > 0)
	{
		push(stack_a, stack_b);
		*commands = ft_comm_add_back(*commands, "pb");
		--ra;
	}
	while ((*stack_a)->if_chain == 1 && ra > 0)
	{
		rotate(stack_a);
		*commands = ft_comm_add_back(*commands, "ra");
	}
	while ((*stack_a)->if_chain == 0 && ra > 0)
	{
		push(stack_a, stack_b);
		*commands = ft_comm_add_back(*commands, "pb");
		--ra;
	}
}
