/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:40:09 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/09 11:40:10 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list		*ft_list_ndup(t_list *list, int size)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = list;
	while (tmp && size > 0)
	{
		new = ft_list_add_back(new, tmp->data);
		tmp = tmp->next;
		--size;
	}
	return (tmp);
}
