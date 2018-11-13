/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:39:50 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/11 13:30:49 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_checker(int argc, int flag_c, int flag_v, t_list **stack)
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