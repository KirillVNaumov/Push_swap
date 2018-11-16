/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:36:02 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 18:36:04 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_else_push_back(t_list **stack_b, t_comm **commands,
	int end_sorted, int list_size)
{
	int list_b_pos;

	list_b_pos = find_in_list(*stack_b, end_sorted);
	if (list_b_pos > list_size / 2)
	{
		while ((*stack_b)->pos != end_sorted)
		{
			reverse_rotate(stack_b);
			*commands = ft_comm_add_back((*commands), "rrb");
		}
	}
	else
		while ((*stack_b)->pos != end_sorted)
		{
			rotate(stack_b);
			*commands = ft_comm_add_back((*commands), "rb");
		}
}

int		push_back(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int last_sorted)
{
	int	list_size;
	int	end_sorted;
	int	ret;

	if (!(*stack_b))
		return (0);
	list_size = ft_list_size(*stack_b);
	first_two(stack_a, stack_b, commands);
	end_sorted = find_the_biggest_sequence(*stack_b, last_sorted);
	ret = end_sorted;
	while (end_sorted > last_sorted)
	{
		if_else_push_back(stack_b, commands, end_sorted, list_size);
		push(stack_b, stack_a);
		*commands = ft_comm_add_back((*commands), "pa");
		end_sorted--;
	}
	return (ret - 1);
}
