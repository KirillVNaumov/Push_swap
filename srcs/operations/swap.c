/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:44:45 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/09 11:44:46 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		swap(t_list **list)
{
	t_list		*elem1;
	t_list		*elem2;
	int			tmp;

	if (ft_list_size(*list) < 2)
		return ;
	elem1 = *list;
	elem2 = elem1->next;
	tmp = elem1->data;
	elem1->data = elem2->data;
	elem2->data = tmp;
}
