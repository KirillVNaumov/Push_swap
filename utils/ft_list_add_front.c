/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 22:03:32 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/05 22:04:09 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

t_list	*ft_list_add_front(t_list *list, int data)
{
	t_list		*node;

	if (list == NULL)
	{
		list = (t_list *)malloc(sizeof(t_list));
		list->data = data;
		list->next = NULL;
		return (list);
	}
	node = (t_list *)malloc(sizeof(t_list));
	node->next = list;
	node->data = data;
	return (node);
}
