/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:47:56 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/21 11:47:58 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_comm	*optimize(t_comm *commands)
// {
// 	while (check_for_right_commnds(commands) == 0)
// 		commands = optimize_answer(commands);
// 	commands = check_for_two_stack_rotations(commands);
// 	return (commands);
// }

int			count_reverse_rotate(t_list *stack, int pos)
{
	int		count;
	t_list	*temp;

	temp = ft_list_dup(stack);
	count = 0;
	while (temp->pos != pos)
	{
		reverse_rotate(&temp);
		++count;
	}
	ft_list_clean(&temp);
	return (count);
}

int			count_rotate(t_list *stack, int pos)
{
	int		count;
	t_list	*temp;

	temp = ft_list_dup(stack);
	count = 0;
	while (temp->pos != pos)
	{
		rotate(&temp);
		++count;
	}
	ft_list_clean(&temp);
	return (count);
}

void			reverse_rotate_until(t_list **stack, int pos)
{
	while ((*stack)->pos != pos)
		reverse_rotate(stack);
}

void			rotate_until(t_list **stack, int pos)
{
	while ((*stack)->pos != pos)
		rotate(stack);
}

int		find_the_last_number(t_list *stack_a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (stack_a)
	{
		tmp = stack_a;
		while (tmp)
		{
			if (i < tmp->pos)
				i = tmp->pos;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (i);
}

int			find_the_biggest_chain(t_list *stack_a)
{
	int		max_length;
	int		length;
	int		begin_pos;
	int		tracker;
	int		last;

	last = find_the_last_number(stack_a);
	rotate_until(&stack_a, 1);
	tracker = 0;
	length = 0;
	max_length = 0;
	begin_pos = 1;
	if (ft_list_size(stack_a) == 1)
		return (1);
	while (stack_a->pos)
	{
		if (length != 0 && stack_a->pos < stack_a->next->pos)
			++length;
		if (length == 0 && stack_a->pos < stack_a->next->pos)
		{
			++length;
			tracker = stack_a->pos;
		}
		if (stack_a->pos > stack_a->next->pos)
		{
			if (length > max_length)
			{
				max_length = length;
				begin_pos = tracker;
			}
			length = 0;
		}
		rotate(&stack_a);
		if (stack_a->pos == 1)
			break ;
	}
	ft_list_clean(&stack_a);
	return (begin_pos);
}

void	push_b_but_chain(t_list **stack_a, t_list **stack_b, t_comm *commands)
{
	t_comm *temp;

	temp = commands;

	while ((*stack_a)->if_chain != 1)
		push(stack_a, stack_b);
	while ((*stack_a)->if_chain != 0)
		rotate(stack_a);
	while ((*stack_a)->if_chain != 1)
		push(stack_a, stack_b);
}

void	define_biggest_chain(t_list **stack_a, int beginning_chain)
{
	int		head;

	head = (*stack_a)->pos;
	while ((*stack_a)->pos != beginning_chain)
	{
		(*stack_a)->if_chain = 0;
		rotate(stack_a);
	}
	while ((*stack_a)->pos < (*stack_a)->next->pos)
	{
		(*stack_a)->if_chain = 1;
		rotate(stack_a);
	}
	(*stack_a)->if_chain = 1;
	rotate(stack_a);
	while ((*stack_a)->pos != beginning_chain)
	{
		(*stack_a)->if_chain = 0;
		rotate(stack_a);
	}
	rotate_until(stack_a, head);
}

int		find_solution(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*temp;
	t_comm	*commands;
	int		beginning_chain;

	commands = NULL;
	stack_b = NULL;
	*stack_a = list_assign_pos(*stack_a);

	temp =  ft_list_dup(*stack_a);
	beginning_chain = find_the_biggest_chain(temp);

	ft_printf("biggest chain == %d\n", beginning_chain);

	define_biggest_chain(stack_a, beginning_chain);
	push_b_but_chain(stack_a, &stack_b, commands);

	ft_printf("Stack a:\n");
	while (*stack_a)
	{
		ft_printf("%d -- %d\n", (*stack_a)->data, (*stack_a)->if_chain);
		(*stack_a) = (*stack_a)->next;
	}
	ft_printf("Stack b:\n");
	while (stack_b)
	{
		ft_printf("%d -- %d\n", stack_b->data, stack_b->if_chain);
		stack_b = stack_b->next;
	}
	return (0);
}
