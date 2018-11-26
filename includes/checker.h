/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:27:57 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/10 14:41:26 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "operations.h"

int		read_output(t_list **stack_a, int flag_v, int flag_c);
void	check_result(t_list **stack_a, t_list **stack_b);
void	error_checker(int argc, int flag_c, int flag_v, t_list **stack);

#endif
