/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:39:13 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/19 13:12:18 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_push_swap(int flag_optimized, t_list **stack)
{
	*stack = list_assign_pos(*stack);
	if (*stack == NULL)
	{
		ft_printf("Error\n");
		return ;
	}
	if (check_for_duplicates(*stack) == -1)
	{
		ft_printf("Error\n");
		return ;
	}
	if (find_optimal_solution(*stack, flag_optimized) == 0)
		find_solution(stack);
}
