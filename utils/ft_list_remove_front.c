/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 22:20:34 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/14 16:35:18 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			ft_list_remove_front(t_list **list)
{
	t_list		*tmp;
	t_list		*node;

	if (*list == NULL)
		return ;
	if (ft_list_size(*list) == 1)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	tmp = *list;
	node = tmp->next;
	if (tmp)
	{
		tmp->next = NULL;
		free(tmp);
	}
	*list = node;
}
