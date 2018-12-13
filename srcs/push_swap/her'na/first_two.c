/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:48:23 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/21 11:48:25 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_two(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	if (ft_list_size(*stack_a) >= 2 && ft_list_size(*stack_b) >= 2)
	{
		if (((*stack_a)->pos - (*stack_a)->next->pos == 1)
		&& ((*stack_b)->pos - (*stack_b)->next->pos == -1))
		{
			swap(stack_a);
			swap(stack_b);
			*commands = ft_comm_add_back((*commands), "ss");
		}
	}
	else
	{
		if (ft_list_size(*stack_a) >= 2)
			if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
			{
				swap(stack_a);
				*commands = ft_comm_add_back((*commands), "sa");
			}
		if (ft_list_size(*stack_b) >= 2)
			if ((*stack_b)->pos - (*stack_b)->next->pos == -1)
			{
				swap(stack_b);
				*commands = ft_comm_add_back((*commands), "sb");
			}
	}
}
