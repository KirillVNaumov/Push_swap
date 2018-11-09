/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 22:02:55 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/06 16:27:40 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_list_add_back(t_list *list, int data)
{
	t_list		*begining;
	t_list		*node;

	if (list == NULL)
	{
		list = (t_list *)malloc(sizeof(t_list));
		list->data = data;
		list->pos = 0;
		list->next = NULL;
		return (list);
	}
	node = (t_list *)malloc(sizeof(t_list));
	begining = list;
	node->next = NULL;
	node->data = data;
	node->pos = 0;
	while (list->next)
		list = list->next;
	list->next = node;
	return (begining);
}
