/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:48:27 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/09 11:49:04 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int argc, char **argv)
{
	int		i;
	int		flag_v;
	int		flag_c;
	t_list	*stack;

	if (argc == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	i = 1;
	flag_v = 0;
	stack = NULL;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-v"))
		{
			flag_v = 1;
			++i;
			continue ;
		}
		if (!ft_strcmp(argv[i], "-c"))
		{
			flag_c = 1;
			++i;
			continue ;
		}
		if (check_for_number(argv[i]) == -1 || check_for_integer(argv[i]) == -1)
		{
			ft_printf("Error\n");
			return (0);
		}
		stack = ft_list_add_back(stack, ft_atoi(argv[i++]));
	}
	if (stack == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (read_output(&stack, flag_v, flag_c) == -1)
		ft_printf("Error\n");
}
