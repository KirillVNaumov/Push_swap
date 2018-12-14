/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:28:26 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/14 13:15:28 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"

// RECURSION

void				error_push_swap(int flag_optimized, t_list **stack);
int					find_solution(t_list **stack_a);
int					find_optimal_solution(t_list *stack_a, int flag_optimized);

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
int					check_answer(t_list *stack_a, t_list *stack_b);
int			count_reverse_rotate(t_list *stack, int pos);
int			count_rotate(t_list *stack, int pos);
void		reverse_rotate_until(t_list **stack, int pos);
void		rotate_until(t_list **stack, int pos);
void        find_and_apply_minimal_oper(t_list **stack_a, t_list **stack_b);
void        assign_comm_ra_rb(t_minimal *min, t_comm **commands);
void        assign_comm_rra_rb(t_minimal *min, t_comm **commands);
void        assign_comm_ra_rrb(t_minimal *min, t_comm **commands);
void        assign_comm_rra_rrb(t_minimal *min, t_comm **commands);

void				count_rotate_rev_rotate(t_list *stack, int pos, int *r, int *rr);

// PREVIOUS TRY

// t_comm				*optimize_answer(t_comm *commands);
// void				first_two(t_list **stack_a,
// 	t_list **stack_b, t_comm **commands);
// int					push_while(t_list **stack_a, t_list **stack_b,
// 	t_comm **commands);
// void				push_b_while(t_list **stack_a, t_list **stack_b,
// 	t_comm **commands, int last_sorted);
// int					find_the_biggest_sequence(t_list *stack_b, int last_sorted);
// int					push_back(t_list **stack_a, t_list **stack_b,
// 	t_comm **commands, int last_sorted);
// void				rotate_back(t_list **stack_a,
// 	t_comm **commands, int num);
// int					check_for_right_commnds(t_comm *commands);
// int					check_if(char *s1, char *s2);
// int					check_if_2(char *s1, char *s2);
// int					check_if_3(char *s1, char *s2);
// void				if_check_if(t_comm **commands);
// void				fix_double_rotations(char *s1, char *s2, \
// 	t_comm **commands, t_comm **new);
// int					solver(t_list **stack_a, t_list **stack_b,
// 	t_comm **commands, int end);

#endif
