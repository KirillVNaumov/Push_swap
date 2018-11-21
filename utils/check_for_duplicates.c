/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_duplicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:45:38 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/09 11:46:49 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			check_for_duplicates(t_list *stack)
{
	t_list	*tmp;
	int		count;

	while (stack)
	{
		count = 0;
		tmp = stack;
		while (tmp)
		{
			if (stack->data == tmp->data)
			{
				count++;
				if (count > 1)
					return (-1);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
