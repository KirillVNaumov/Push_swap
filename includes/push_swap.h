/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:28:26 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/11 13:33:14 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"
# include "operations.h"
# include "checker.h"

void	error_push_swap(int argc, int flag_c, int flag_v, t_list **stack);
int		find_solution(t_list **stack_a, int flag_v, int flag_c);
int		solver(t_list **stack_a, t_list **stack_b);

#endif
