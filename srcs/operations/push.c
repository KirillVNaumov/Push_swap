/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:43:47 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/14 14:33:04 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		push(t_list **src, t_list **dst)
{
	t_list		*tmp;

	if (ft_list_size(*src) < 1)
		return ;
	tmp = *src;
	*dst = ft_list_add_front(*dst, tmp->data, tmp->pos, tmp->if_chain);
	ft_list_remove_front(src);
}
