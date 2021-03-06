/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:21:53 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/22 15:14:27 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		free_double(char ***argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(*argv)[i])
		return ;
	while ((*argv)[i])
		i++;
	while (j < i)
	{
		free((*argv)[j]);
		j++;
	}
	free(*argv);
}

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
			free_double(&arg);
			return (0);
		}
		free_double(&arg);
		(*i)++;
	}
	return (1);
}
