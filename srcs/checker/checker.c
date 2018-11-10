/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:48:27 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/09 16:04:06 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main_helper_function(int i, int argc, char **argv, t_list **stack)
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

void	oh_plz(char **argv, int *i, int *flag_c, int *flag_v)
{
	if (!ft_strcmp(argv[*i], "-v"))
	{
		*flag_v = 1;
		(*i)++;
	}
	if (!ft_strcmp(argv[*i], "-c"))
	{
		*flag_c = 1;
		(*i)++;
	}
}

void	check_for_error(int argc, int flag_c, int flag_v, t_list **stack)
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
		oh_plz(argv, &i, &flag_c, &flag_v);
		if (main_helper_function(i, argc, argv, &stack) == 0)
			return (0);
	}
	check_for_error(argc, flag_c, flag_v, &stack);
}
