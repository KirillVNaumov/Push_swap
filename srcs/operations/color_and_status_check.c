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

void	color_and_status_check(char **argv, int *i, int *flag_c, int *flag_v)
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
