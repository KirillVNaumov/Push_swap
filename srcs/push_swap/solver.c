/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:48:54 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/14 19:43:09 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_in_list(t_list *root, int num)
{
	int		i;
	t_list	*entity;

	i = 1;
	if (!root)
		return (0);
	if (root)
	{
		entity = root;
		while (entity)
		{
			if (entity->pos == num)
				break ;
			(entity = entity->next) && i++;
		}
	}
	return (i);
}

void	first_two(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	if (ft_list_size(*stack_a) >= 2 && ft_list_size(*stack_b) >= 2)
	{
		if (((*stack_a)->pos - (*stack_a)->next->pos == 1)
		&& ((*stack_b)->pos - (*stack_b)->next->pos == -1))
		{
			swap(stack_a);
			swap(stack_b);
			ft_comm_add_back((*commands), "ss");
		}
	}
	else
	{
		if (ft_list_size(*stack_a) >= 2)
			if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
			{
				swap(stack_a);
				ft_comm_add_back((*commands), "sa");
			}
		if (ft_list_size(*stack_b) >= 2)
			if ((*stack_b)->pos - (*stack_b)->next->pos == -1)
			{
				swap(stack_b);
				ft_comm_add_back((*commands), "sb");
			}
	}
}

int		push_while(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	int ret;
	int list_size;
	int where_is_one;

	list_size = ft_list_size(*stack_a);
	where_is_one = find_in_list(*stack_a, 1);
	while ((*stack_a)->pos != 1)
	{
		if (where_is_one > list_size / 2)
		{
			reverse_rotate(stack_a);
			ft_comm_add_back((*commands), "rra");
		}
		else
		{
			rotate(stack_a);
			ft_comm_add_back((*commands), "ra");
		}
	}
	while ((*stack_a)->pos - (*stack_a)->next->pos == -1)
	{
		if (check_answer(*stack_a, *stack_b) == 1)
		{
			reverse_rotate(stack_a);
			ret = (*stack_a)->pos;
			rotate(stack_a);
			return (ret);
		}
		rotate(stack_a);
		first_two(stack_a, stack_b, commands);
	}
	ret = (*stack_a)->pos;
	rotate(stack_a);
	return (ret);
}

void	push_b_while(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int last_sorted)
{
	t_list *tmp;

	tmp = ft_list_dup(*stack_a);
	if (ft_list_size(tmp) < last_sorted + 1)
		return ;
	while ((*stack_a)->pos != last_sorted)
	{
		push(stack_a, stack_b);
		ft_comm_add_back((*commands), "pb");
		first_two(stack_a, stack_b, commands);
	}
}

int		find_the_biggest_sequence(t_list *stack_b, int last_sorted)
{
	t_list	*tmp;
	int		end;

	tmp = stack_b;
	last_sorted++;
	end = last_sorted;
	while (stack_b)
	{
		while (tmp)
		{
			if (last_sorted == stack_b->pos)
			{
				last_sorted++;
				end++;
			}
			tmp = tmp->next;
		}
		stack_b = stack_b->next;
	}
	return (end);
}

void	push_back(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int last_sorted)
{
	int list_size;
	int list_b_pos;
	int end_sorted;

	if (!(*stack_b))
		return ;
	list_size = ft_list_size(*stack_b);
	list_b_pos = find_in_list(*stack_b, last_sorted);
	first_two(stack_a, stack_b, commands);
	end_sorted = find_the_biggest_sequence(*stack_b, last_sorted);
	while (end_sorted > last_sorted)
	{
		list_b_pos = find_in_list(*stack_b, end_sorted);
		if (list_b_pos > list_size / 2)
		{
			while ((*stack_b)->pos != end_sorted)
			{
				reverse_rotate(stack_b);
				ft_comm_add_back((*commands), "rrb");
			}
		}
		else
			while ((*stack_b)->pos != end_sorted)
			{
				rotate(stack_b);
				ft_comm_add_back((*commands), "rb");
			}
		push(stack_b, stack_a);
		end_sorted--;
	}
}

int		solver(t_list *stack_a, t_list *stack_b, t_comm *commands)
{
	int last_sorted;
	t_list *tmp = stack_a;

	stack_a = list_assign_pos(stack_a);
	first_two(&stack_a, &stack_b, &commands);
	last_sorted = push_while(&stack_a, &stack_b, &commands);
	// ft_printf("ls: %d\n", last_sorted);
	push_b_while(&stack_a, &stack_b, &commands, last_sorted);
	push_back(&stack_a, &stack_b, &commands, last_sorted);
	tmp = stack_a;
	while (tmp)
	{
		ft_printf("%d--%d\n", tmp->data, tmp->pos);
		tmp = tmp->next;
	}
	ft_printf("------------\n");
	if (check_answer(stack_a, stack_b) == 1)
		return (1);
	return (0);
}
