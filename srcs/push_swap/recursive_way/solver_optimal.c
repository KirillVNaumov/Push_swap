/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_optimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:15:00 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/15 16:15:40 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		search(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	if (check_answer(stack_a, stack_b) == 1)
		return (1);
	if (set_depth == 0)
		return (-1);
	if (swap_rec(stack_a, stack_b, set_depth, command_list) == 1)
		return (1);
	if (push_rec(stack_a, stack_b, set_depth, command_list) == 1)
		return (1);
	if (rotate_rec(stack_a, stack_b, set_depth, command_list) == 1)
		return (1);
	if (reverse_rotate_rec(stack_a, stack_b, set_depth, command_list) == 1)
		return (1);
	return (-1);
}
