/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 22:03:32 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/14 14:31:54 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_list_add_front(t_list *list, int data, int pos)
{
	t_list		*node;

	if (list == NULL)
	{
		list = (t_list *)malloc(sizeof(t_list));
		list->data = data;
		list->next = NULL;
		list->pos = pos;
		return (list);
	}
	node = (t_list *)malloc(sizeof(t_list));
	node->next = list;
	node->data = data;
	node->pos = pos;
	return (node);
}
