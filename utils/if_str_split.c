/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:21:53 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/21 13:22:37 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			if_str_split(char **argv, t_list **stack, int *i)
{
	char	**arg;

	while (argv[*i])
	{
		arg = ft_strsplit(argv[*i], ' ');
		if (add_to_list(0, arg, stack) == 0)
		{
			if (*stack)
				ft_list_clean(stack);
			return (0);
		}
		(*i)++;
	}
	return (1);
}