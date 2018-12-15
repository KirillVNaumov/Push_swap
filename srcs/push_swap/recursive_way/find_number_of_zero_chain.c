/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number_of_zero_chain.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:19:14 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 16:19:15 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_number_of_zero_chain(t_list *stack)
{
	int zeros;

	zeros = 0;
	while (stack)
	{
		if (stack->if_chain == 0)
			zeros++;
		stack = stack->next;
	}
	return (zeros);
}
