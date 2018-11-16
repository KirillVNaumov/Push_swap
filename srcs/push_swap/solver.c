/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:48:54 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 18:36:53 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		solver(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	int	last_sorted;

	first_two(stack_a, stack_b, commands);
	last_sorted = push_while(stack_a, stack_b, commands);
	push_b_while(stack_a, stack_b, commands, last_sorted);
	last_sorted = push_back(stack_a, stack_b, commands, last_sorted);
	rotate_back(stack_a, commands, last_sorted);
	if (check_answer(*stack_a, *stack_b) == 1)
		return (1);
	return (0);
}
