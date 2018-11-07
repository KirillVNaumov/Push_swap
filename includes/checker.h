/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:27:57 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/05 15:39:18 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"
# include "operations.h"

int			read_output(t_list **stack_a, int flag_v);
void		check_result(t_list **stack_a, t_list *stack_b);
void		print_status(t_list *stack_a, t_list *stack_b);
// void		check_duplicates(t_list *stack_a);

# endif
