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

# include "utils.h"
# include "operations.h"
# include "push_swap.h"

int		read_output(t_list **stack_a, int flag_v, int flag_c);
void	check_result(t_list **stack_a, t_list *stack_b);
int		check_for_integer(char *str);
int		check_for_number(char *str);
int		check_for_duplicates(t_list *stack_a);
void	color_and_status_check(char **argv, int *i, int *flag_c, int *flag_v);
void	error_checker(int argc, int flag_c, int flag_v, t_list **stack);
int		add_to_list(int i, int argc, char **argv, t_list **stack);

#endif
