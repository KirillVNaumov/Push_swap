/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_while.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:34:19 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 18:34:19 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_while(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int last_sorted)
{
	t_list *tmp;

	tmp = ft_list_dup(*stack_a);
	if (ft_list_size(tmp) < last_sorted + 1)
		return ;
	while ((*stack_a)->pos != last_sorted + 1)
	{
		push(stack_a, stack_b);
		*commands = ft_comm_add_back((*commands), "pb");
	}
	if ((*stack_a)->pos == last_sorted + 1)
	{
		push(stack_a, stack_b);
		*commands = ft_comm_add_back((*commands), "pb");
	}
}
