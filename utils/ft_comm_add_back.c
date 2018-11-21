/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comm_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:50:33 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/21 11:50:34 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_comm	*ft_comm_add_back(t_comm *list, char *command)
{
	t_comm		*begining;
	t_comm		*node;

	if (list == NULL)
	{
		list = (t_comm *)malloc(sizeof(t_comm));
		list->command = ft_strdup(command);
		list->next = NULL;
		return (list);
	}
	node = (t_comm*)malloc(sizeof(t_comm));
	begining = list;
	node->next = NULL;
	node->command = ft_strdup(command);
	while (list->next)
		list = list->next;
	list->next = node;
	return (begining);
}
