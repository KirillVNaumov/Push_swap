/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:14:56 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/06 15:16:44 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list		*ft_list_dup(t_list *list)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = list;
	if (list == NULL)
		return (NULL);
	while (tmp)
	{
		new = ft_list_add_back(new, tmp->data);
		tmp = tmp->next;
	}
	return (new);
}
