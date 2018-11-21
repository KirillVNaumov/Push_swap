/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comm_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:43:50 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/19 15:44:02 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_comm_clean(t_comm **comm)
{
	t_comm *node;

	if (*comm == NULL)
		return ;
	node = *comm;
	if (node->next)
		ft_comm_clean(&node->next);
	free((*comm)->command);
	free(*comm);
}
