/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:49:14 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/14 15:59:32 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		flag_optimized;
	t_list	*stack;
	int		flag_c;
	int		flag_v;

	flag_optimized = 0;
	stack = NULL;
	if (argc >= 2)
	{
		i = color_and_status_check(argv, &flag_c, &flag_v, &flag_optimized);
		if (flag_c == 1 || flag_v == 1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (if_str_split(argv, &stack, &i) == 0)
			return (0);
	}
	else
	{
		ft_printf("Usage: ./push_swap [stack of numbers]\n");
		return (1);
	}
	error_push_swap(flag_optimized, &stack);
}
