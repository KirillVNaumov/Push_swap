/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:48:54 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/13 19:23:11 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void	first_two(t_list **stack_a, t_list **stack_b, t_list **commands)
// {
// 	if ((stack_a->pos - stack_a->next->pos == -1)
// 	&& (stack_b->pos - stack_b->next->pos == -1))
// 	{
// 		swap(&stack_a);
// 		swap(&stack_b);
// 		ft_comm_add_back((*commands), "ss");
// 	}
// 	else
// 	{
// 		if (stack_a->pos - stack_a->next->pos == -1)
// 		{
// 			swap(&stack_a)
// 			ft_comm_add_back((*commands), "sa");
// 		}
// 		if (stack_b->pos - stack_b->next->pos == -1)
// 		{
// 			swap(&stack_b)
// 			ft_comm_add_back((*commands), "sb");
// 		}
// 	}
// }

// int		push_while(t_list **stack_a, t_list **stack_b, t_comm **commands)
// {
// 	while((*stack_a)->pos - (*stack_a)->next->pos == 1)
// 	{
// 		rotate(stack_a);
// 		ft_comm_add_back((*commands), "ra");
// 	}
// 	return ((*stack_a)->pos);
// }

// void	push_b_while(t_list **stack_a, t_list **stack_b,
// 	t_comm **commands, int last_sorted)
// {
// 	while((*stack_a)->pos != last_sorted + 1))
// 	{
// 		first_two(stack_a, stack_b, commands);
// 		push(stack_a, stack_b);
// 		ft_comm_add_back("pb");
// 	}
// }

// void	push_back(t_list **stack_a, t_list **stack_b,
// 	t_comm **commands, int last_sorted)
// {
// 	while((*stack_b)
// }

// int		solver(t_list *stack_a, t_list *stack_b, t_comm *commands)
// {
// 	int last_sorted;

// 	first_two(&stack_a, &stack_b, &commands);
// 	last_sorted = push_while(&stack_a, &stack_b, &commands);
// 	push_b_while(&stack_a, &stack_b, &commands);
// 	push_back(&stack_a, &stack_b, &commands, last_sorted);
// 	if (check_answer(stack_a, stack_b) == 1)
// 		return (1);
// 	return (0);
// }
