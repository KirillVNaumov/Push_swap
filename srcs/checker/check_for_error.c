/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:31:01 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/10 14:31:10 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_for_error(int argc, int flag_c, int flag_v, t_list **stack)
{
	if (argc == 1)
	{
		ft_printf("Error\n");
		return ;
	}
	if (*stack == NULL)
	{
		ft_printf("Error\n");
		return ;
	}
	if (read_output(stack, flag_v, flag_c) == -1)
	{
		ft_printf("Error\n");
		return ;
	}
}
