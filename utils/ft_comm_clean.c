/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comm_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:50:44 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/14 18:17:43 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_comm_clean(t_comm **comm)
{
	t_comm *node;

	if (*comm == NULL || comm == NULL)
		return ;
	node = *comm;
	if (node->next)
		ft_comm_clean(&node->next);
	free((*comm)->command);
	free(*comm);
}
