/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:44:33 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/14 14:32:51 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		rotate(t_list **list)
{
	t_list	*node;

	if (ft_list_size(*list) < 2)
		return ;
	node = *list;
	*list = ft_list_add_back(*list, node->data, node->pos);
	ft_list_remove_front(list);
}
