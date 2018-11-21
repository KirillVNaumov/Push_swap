/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:50:18 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/21 11:50:19 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		find_in_list(t_list *root, int num)
{
	int		i;
	t_list	*entity;

	i = 1;
	if (!root)
		return (0);
	if (root)
	{
		entity = root;
		while (entity)
		{
			if (entity->pos == num)
				break ;
			(entity = entity->next) && i++;
		}
	}
	return (i);
}
