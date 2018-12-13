/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_comm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:03:41 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/15 16:04:05 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_last_comm(t_comm *list, char *command)
{
	if (list == NULL)
		return (-1);
	while (list->next)
		list = list->next;
	if (!ft_strcmp(list->command, command))
		return (1);
	return (-1);
}
