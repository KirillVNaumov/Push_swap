/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:47:56 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/14 16:08:09 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		find_number_of_zero_chain(t_list *stack)
{
	int zeros;

	zeros = 0;
	while (stack)
	{
		if (stack->if_chain == 0)
			zeros++;
		stack = stack->next;
	}
	return (zeros);
}

void	push_b_but_chain(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	int	ra;

	ra = find_number_of_zero_chain(*stack_a);
	while ((*stack_a)->if_chain == 0 && ra > 0)
	{
		push(stack_a, stack_b);
		*commands = ft_comm_add_back(*commands, "pb");
		--ra;
	}
	while ((*stack_a)->if_chain == 1 && ra > 0)
	{
		rotate(stack_a);
		*commands = ft_comm_add_back(*commands, "ra");
	}
	while ((*stack_a)->if_chain == 0 && ra > 0)
	{
		push(stack_a, stack_b);
		*commands = ft_comm_add_back(*commands, "pb");
		// ft_printf("pb\n");
		--ra;
	}
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

	stack_b = NULL;
	commands = NULL;
	*stack_a = list_assign_pos(*stack_a);
	temp = ft_list_dup(*stack_a);
	beginning_chain = find_the_biggest_chain(temp);
	define_biggest_chain(stack_a, beginning_chain);
	push_b_but_chain(stack_a, &stack_b, &commands);
	while (stack_b != NULL)
		find_and_apply_minimal_oper(stack_a, &stack_b, &commands);
	if (count_rotate(*stack_a, 1) < count_reverse_rotate(*stack_a, 1))
		while ((*stack_a)->pos != 1)
		{
			commands = ft_comm_add_back(commands, "ra");
			rotate(stack_a);
		}
	else
		while ((*stack_a)->pos != 1)
		{
			commands = ft_comm_add_back(commands, "rra");
			reverse_rotate(stack_a);
		}
	while (commands)
	{
		ft_printf("%s\n", commands->command);
		commands = commands->next;
	}
	return (0);
}
