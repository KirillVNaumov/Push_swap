/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:30:16 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 18:30:31 by amelikia         ###   ########.fr       */
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
