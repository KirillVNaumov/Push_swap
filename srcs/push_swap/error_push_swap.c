/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:39:13 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/11 13:35:54 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_push_swap(int argc, int flag_c, int flag_v, t_list **stack)
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
	if (find_solution(stack, flag_v, flag_c) == -1)
	{
		ft_printf("Error\n");
		return ;
	}
}
