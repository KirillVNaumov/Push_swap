/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:48:12 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/20 21:13:17 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		check_result(t_list **stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (stack_b)
	{
		ft_printf("KO\n");
		return ;
	}
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			ft_printf("KO\n");
			return ;
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
}
