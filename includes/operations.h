/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:38:22 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/09 11:36:23 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "utils.h"

void		swap(t_list **list);
void		push(t_list **src, t_list **dst);
void		rotate(t_list **list);
void		reverse_rotate(t_list **list);
void		print_status(t_list *stack_a, t_list *stack_b, int color);

#endif
