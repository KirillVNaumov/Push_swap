/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:42:12 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/11 13:35:09 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_solution(t_list **stack_a, int flag_v, int flag_c)
{
	t_list	*stack_b;
	int		stop;

	stop = 0;
	stack_b = NULL;
	if (check_for_duplicates(*stack_a) == -1)
		return (-1);
	*stack_a = list_assign_pos(*stack_a);
	while (1)
	{
		// if (solver(stack_a, &stack_b) == 1)
		// 	stop = 1;
		if (flag_v == 1)
			print_status(*stack_a, stack_b, flag_c);
		if (stop == 1)
			break ;
	}
	return (0);
}
