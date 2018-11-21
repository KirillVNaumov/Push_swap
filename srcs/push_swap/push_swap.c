/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:38:58 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/20 21:22:07 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		flag_optimized;
	t_list	*stack;

	flag_optimized = 0;
	stack = NULL;
	if (argc >= 2)
	{
		i = color_and_status_check(argv, 0, 0, &flag_optimized);
		if (add_to_list(i, argc, argv, &stack) == 0)
			return (0);
	}
	else
	{
		ft_printf("Usage: ./push_swap [stack of numbers]\n");
		return (1);
	}
	error_push_swap(flag_optimized, &stack);
}
