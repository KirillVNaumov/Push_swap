/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:48:27 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/10 14:37:32 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	int		i;
	int		flag_v;
	int		flag_c;
	t_list	*stack;

	i = 1;
	flag_v = 0;
	flag_c = 0;
	stack = NULL;
	if (argc >= 2)
	{
		color_and_status_check(argv, &i, &flag_c, &flag_v);
		if (add_to_list(i, argc, argv, &stack) == 0)
			return (0);
	}
	stack = list_assign_pos(stack);
	error_checker(argc, flag_c, flag_v, &stack);
}
