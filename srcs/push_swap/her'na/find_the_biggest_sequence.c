/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_biggest_sequence.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:48:10 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/21 11:48:12 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_the_biggest_sequence(t_list *stack_b, int last_sorted)
{
	t_list	*tmp;
	int		end;

	tmp = stack_b;
	last_sorted++;
	end = last_sorted;
	while (tmp)
	{
		if (tmp->pos == end + 1)
		{
			++end;
			tmp = stack_b;
		}
		else
			tmp = tmp->next;
	}
	return (end);
}
