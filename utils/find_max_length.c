/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:37:53 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/15 16:02:35 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			find_max_length(t_list *list)
{
	int			max;
	int			tmp;
	int			count;

	max = 0;
	while (list)
	{
		tmp = list->data;
		if (tmp == -2147483648)
			return (11);
		count = 0;
		if (tmp < 0)
			count = 1;
		if (tmp < 0)
			tmp = -tmp;
		while (tmp > 9)
		{
			tmp = tmp / 10;
			++count;
		}
		if (++count > max)
			max = count;
		list = list->next;
	}
	return (max);
}
