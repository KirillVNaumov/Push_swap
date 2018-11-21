/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 22:20:10 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/19 16:29:43 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			ft_list_remove_back(t_list **list)
{
	t_list		*tmp;
	t_list		*node;

	if (*list == NULL)
		return ;
	if (ft_list_size(*list) == 1)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	node = *list;
	while (node->next->next)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
	free(tmp);
}
