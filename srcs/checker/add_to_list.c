/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:31:24 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/10 14:31:25 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		add_to_list(int i, int argc, char **argv, t_list **stack)
{
	while (i < argc)
	{
		if (check_for_number(argv[i]) == -1 || check_for_integer(argv[i]) == -1)
		{
			ft_printf("Error\n");
			return (0);
		}
		*stack = ft_list_add_back((*stack), ft_atoi(argv[i++]));
	}
	return (1);
}
