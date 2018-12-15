/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:49:40 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/14 18:34:06 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_back(t_list **stack_a, int num)
{
	int list_a_size;
	int	where_is_one;

	where_is_one = find_in_list((*stack_a), 1);
	list_a_size = ft_list_size(*stack_a);
	if (where_is_one < list_a_size / 2)
	{
		while (num > 0)
		{
			rotate(stack_a);
			ft_printf("ra\n");
			num--;
		}
	}
	else
	{
		while (num < list_a_size)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
			num++;
		}
	}
}
