/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_biggest_sequence.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:35:25 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 18:35:29 by amelikia         ###   ########.fr       */
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
