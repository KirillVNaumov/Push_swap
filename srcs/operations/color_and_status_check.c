/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_status_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:31:54 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/10 14:31:56 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	color_and_status_check(char **argv, int *flag_c, int *flag_v, int *flag_o)
{
	int j;
	int	i;

	j = 0;
	i = 1;
	while(j <= 2)
	{
		if (argv[i] && !ft_strcmp(argv[i], "-v"))
		{
			*flag_v = 1;
			i++;
		}
		if (argv[i] && !ft_strcmp(argv[i], "-c"))
		{
			*flag_c = 1;
			i++;
		}
		if (argv[i] && !ft_strcmp(argv[i], "-o"))
		{
			*flag_o = 1;
			i++;
		}
		j++;
	}
	return (i);
}
