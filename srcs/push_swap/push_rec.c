/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:05:42 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/15 16:07:59 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			push_rec_pa(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	if (check_last_comm(*command_list, "pb") == 1 || stack_b == NULL)
		return (-1);
	*command_list = ft_comm_add_back(*command_list, "pa");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			push_rec_pb(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	if (check_last_comm(*command_list, "pa") == 1 || stack_a == NULL)
		return (-1);
	*command_list = ft_comm_add_back(*command_list, "pb");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			push_rec(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
	push(&temp_b, &temp_a);
	if (push_rec_pa(temp_a, temp_b, set_depth, command_list) == 1)
		return (1);
	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
	push(&temp_a, &temp_b);
	if (push_rec_pb(temp_a, temp_b, set_depth, command_list) == 1)
		return (1);
	return (-1);
}
