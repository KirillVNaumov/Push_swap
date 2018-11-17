/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:28:26 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/16 16:58:06 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"

void				error_push_swap(int flag_optimized, t_list **stack);
int					find_solution(t_list **stack_a);
void				find_optimal_solution(t_list *stack_a);
int					check_answer(t_list *stack_a, t_list *stack_b);
int					solver(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int end);
int					search(t_list *stack_a, t_list *stack_b,
	int set_depth, t_comm **command_list);
int					swap_rec(t_list *stack_a, t_list *stack_b,
	int set_depth, t_comm **command_list);
int					push_rec(t_list *stack_a, t_list *stack_b,
	int set_depth, t_comm **command_list);
int					rotate_rec(t_list *stack_a, t_list *stack_b,
	int set_depth, t_comm **command_list);
int					reverse_rotate_rec(t_list *stack_a, t_list *stack_b,
	int set_depth, t_comm **command_list);
int					check_last_comm(t_comm *list, char *command);
t_comm				*optimize_answer(t_comm *commands);
void				first_two(t_list **stack_a,
	t_list **stack_b, t_comm **commands);
int					push_while(t_list **stack_a, t_list **stack_b,
	t_comm **commands);
void				push_b_while(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int last_sorted);
int					find_the_biggest_sequence(t_list *stack_b, int last_sorted);
int					push_back(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int last_sorted);
void				rotate_back(t_list **stack_a,
	t_comm **commands, int num);
int					check_for_right_commnds(t_comm *commands);

#endif
