/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:31:29 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/05 20:51:08 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

int		ft_list_size(t_list *root)
{
	int		i;
	t_list	*entity;

	i = 0;
	if (root)
	{
		entity = root;
		while (entity)
			(entity = entity->next) && i++;
	}
	return (i);
}
