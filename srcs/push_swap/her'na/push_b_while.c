/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_while.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:48:50 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/21 11:48:51 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_while(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int pos)
{
	t_list *tmp;

	tmp = ft_list_dup(*stack_a);
	if (ft_list_size(tmp) < pos + 1)
	{
		ft_list_clean(&tmp);
		return ;
	}
	while ((*stack_a)->pos != pos + 1)
	{
		push(stack_a, stack_b);
		*commands = ft_comm_add_back((*commands), "pb");
	}
	if ((*stack_a)->pos == pos + 1)
	{
		push(stack_a, stack_b);
		*commands = ft_comm_add_back((*commands), "pb");
	}
	ft_list_clean(&tmp);
}
