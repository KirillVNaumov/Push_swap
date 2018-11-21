/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:45:03 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/05 20:54:47 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_list_clean(t_list **list)
{
	t_list *node;

	if (*list == NULL)
		return ;
	node = *list;
	if (node->next)
		ft_list_clean(&node->next);
	ft_memdel((void**)list);
}
