/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:38:58 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 20:07:10 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		flag_v;
	int		flag_c;
	int		flag_optimized;
	t_list	*stack;

	flag_v = 0;
	flag_c = 0;
	flag_optimized = 0;
	stack = NULL;
	if (argc >= 2)
	{
		i = color_and_status_check(argv, &flag_c, &flag_v, &flag_optimized);
		if (add_to_list(i, argc, argv, &stack) == 0)
			return (0);
	}
	else
	{
		ft_printf("USAGE\n");
		return (1);
	}
	if (argc <= 6)
		flag_optimized = 1;
	error_push_swap(flag_optimized, &stack);
}
