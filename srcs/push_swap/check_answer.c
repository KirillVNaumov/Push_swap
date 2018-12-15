/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:03:20 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/14 16:06:07 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_answer(t_list *stack_a, t_list *stack_b)
{
	t_list		*tmp;

	tmp = stack_a;
	if (stack_b)
		return (-1);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}
