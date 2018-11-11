/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:38:58 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/11 13:24:55 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
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
	error_push_swap(argc, flag_c, flag_v, &stack);
}
