/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:48:27 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/20 21:25:17 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		so_tired(t_list **stack, int flag_o)
{
	if (flag_o == 1)
	{
		ft_printf("Error\n");
		ft_list_clean(stack);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		flag_v;
	int		flag_c;
	int		flag_o;
	t_list	*stack;

	flag_v = 0;
	flag_c = 0;
	flag_o = 0;
	stack = NULL;
	if (argc >= 2)
	{
		i = color_and_status_check(argv, &flag_c, &flag_v, &flag_o);
		if (add_to_list(i, argc, argv, &stack) == 0)
		{
			ft_list_clean(&stack);
			return (0);
		}
	}
	if (so_tired(&stack, flag_o) == 0)
		return (0);
	error_checker(argc, flag_c, flag_v, &stack);
	ft_list_clean(&stack);
}
