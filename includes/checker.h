/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:27:57 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/09 11:36:05 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"
# include "operations.h"

int			read_output(t_list **stack_a, int flag_v, int flag_c);
void		check_result(t_list **stack_a, t_list *stack_b);
int			check_for_integer(char *str);
int			check_for_number(char *str);
int			check_for_duplicates(t_list *stack_a);

#endif
