/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 22:20:34 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/05 22:20:35 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

t_list	*ft_list_remove_front(t_list *list)
{
	t_list		*tmp;

	if (ft_list_size(list) == 0)
		return (NULL);
	if (ft_list_size(list) == 1)
	{
		ft_list_clean(&list);
		return (NULL);
	}
	tmp = list->next;
	free(list);
	return (tmp);
}
