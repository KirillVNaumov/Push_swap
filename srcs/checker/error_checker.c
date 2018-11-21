/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:45:41 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/21 11:45:42 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_checker(int argc, int flag_c, int flag_v, t_list **stack)
{
	*stack = list_assign_pos(*stack);
	if (argc == 1 || *stack == NULL)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (read_output(stack, flag_v, flag_c) == -1)
	{
		write(2, "Error\n", 6);
		return ;
	}
}
