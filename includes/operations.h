/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:38:22 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/14 14:37:37 by amelikia         ###   ########.fr       */
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
int			color_and_status_check(char **argv,
	int *flag_c, int *flag_v, int *flag_o);
int			check_for_integer(char *str);
int			check_for_number(char *str);
int			check_for_duplicates(t_list *stack_a);

#endif
