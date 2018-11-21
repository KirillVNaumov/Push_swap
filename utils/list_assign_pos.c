/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_assign_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:51:16 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/21 11:51:17 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_list		*list_assign_pos(t_list *stack)
{
	t_list		*list1;
	t_list		*list2;
	int			count;

	list1 = stack;
	while (list1)
	{
		list2 = stack;
		count = 0;
		while (list2)
		{
			if (list1->data > list2->data)
				++count;
			list2 = list2->next;
		}
		list1->pos = count + 1;
		list1 = list1->next;
	}
	return (stack);
}
