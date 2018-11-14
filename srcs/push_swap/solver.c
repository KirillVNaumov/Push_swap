/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:48:54 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/14 12:41:22 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
​
int		find_in_list(t_list *root, last_sorted)
{
	int		i;
	t_list	*entity;
​
	i = 1;
	if (!root)
		return (0);
	if (root)
	{
		entity = root;
		while (entity)
		{
			if (entity->data = last_sorted + 1)
				break ;
			(entity = entity->next) && i++;
		}
	}
	return (i);
}
​
void	first_two(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	if (((*stack_a)->pos - (*stack_a)->next->pos == -1)
	&& ((*stack_b)->pos - (*stack_b)->next->pos == 1))
	{
		swap(stack_a);
		swap(stack_b);
		ft_comm_add_back((*commands), "ss");
	}
	else
	{
		if ((*stack_a)->pos - (*stack_a)->next->pos == -1)
		{
			swap(stack_a);
			ft_comm_add_back((*commands), "sa");
		}
		if ((*stack_b)->pos - (*stack_b)->next->pos == 1)
		{
			swap(stack_b);
			ft_comm_add_back((*commands), "sb");
		}
	}
}
​
int		push_while(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	while ((*stack_a)->pos - (*stack_a)->next->pos == 1)
	{
		rotate(stack_a);
		ft_comm_add_back((*commands), "ra");
		first_two(stack_a, stack_b, commands);
	}
	return ((*stack_a)->pos);
}
​
void	push_b_while(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int last_sorted)
{
	while ((*stack_a)->pos != last_sorted + 1)
	{
		push(stack_a, stack_b);
		ft_comm_add_back((*commands), "pb");
		first_two(stack_a, stack_b, commands);
	}
}
​
void	push_back(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int last_sorted)
{
	int list_size;
	int list_b_pos;
	list_size = ft_list_size(stack_b);
	list_b_pos = find_in_list(stack_b, last_sorted);
	if (list_b_pos > list_size / 2)
		while ((*stack_b)->pos != last_sorted + 1)
			reverse_rotate(stack_b);
	while (1)
	{
		first_two(stack_a, stack_b, commands);
		last_b_pos = stack_b->pos;
		reverse_rotate(stack_b);
		if (stack_b->pos)
	}
	ft_comm_add_back((*commands), "rb");
	else
}
​
void	sort_b(t_list **stack_a, t_list **stack_b,
	t_comm **commands)
{
	first_two(stack_a, stack_b, commands);
​
}
​
int		solver(t_list *stack_a, t_list *stack_b, t_comm *commands)
{
	int last_sorted;
​
	first_two(&stack_a, &stack_b, &commands);
	last_sorted = push_while(&stack_a, &stack_b, &commands);
	push_b_while(&stack_a, &stack_b, &commands, last_sorted);
	sort_b(&stack_a, &stack_b, &commands);
	push_back(&stack_a, &stack_b, &commands, last_sorted);
	if (check_answer(stack_a, stack_b) == 1)
		return (1);
	return (0);
}
