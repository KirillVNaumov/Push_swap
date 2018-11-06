/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 22:20:10 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/05 22:20:13 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_remove_back(t_list *list)
{
	t_list		*tmp;

	if (ft_list_size(list) == 0)
		return (NULL);
	if (ft_list_size(list) == 1)
	{
		ft_list_clean(&list);
		return (NULL);
	}
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	free(list);
	return (tmp);
}
