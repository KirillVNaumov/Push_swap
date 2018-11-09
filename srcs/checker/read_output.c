/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:49:21 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/09 11:50:08 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		read_output(t_list **stack_a, int flag_v, int flag_c)
{
	t_list		*stack_b;
	char		*input;

	stack_b = NULL;
	if (check_for_duplicates(*stack_a) == -1)
		return (-1);
	while (get_next_line(0, &input) > 0)
	{
		if (!ft_strcmp(input, "sa"))
			swap(stack_a);
		else if (!ft_strcmp(input, "sb"))
			swap(&stack_b);
		else if (!ft_strcmp(input, "ss"))
		{
			swap(stack_a);
			swap(&stack_b);
		}
		else if (!ft_strcmp(input, "pa"))
			push(&stack_b, stack_a);
		else if (!ft_strcmp(input, "pb"))
			push(stack_a, &stack_b);
		else if (!ft_strcmp(input, "ra"))
			rotate(stack_a);
		else if (!ft_strcmp(input, "rb"))
			rotate(&stack_b);
		else if (!ft_strcmp(input, "rr"))
		{
			rotate(stack_a);
			rotate(&stack_b);
		}
		else if (!ft_strcmp(input, "rra"))
			reverse_rotate(stack_a);
		else if (!ft_strcmp(input, "rrb"))
			reverse_rotate(&stack_b);
		else if (!ft_strcmp(input, "rrr"))
		{
			reverse_rotate(stack_a);
			reverse_rotate(&stack_b);
		}
		else if (!ft_strcmp(input, "exit"))
			break ;
		else
			return (-1);
		if (flag_v == 1)
			print_status(*stack_a, stack_b, flag_c);
		ft_strdel(&input);
	}
	check_result(stack_a, stack_b);
	return (0);
}
