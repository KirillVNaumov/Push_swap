/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:48:54 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 18:20:44 by amelikia         ###   ########.fr       */
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
			*commands = ft_comm_add_back((*commands), "ss");
		}
	}
	else
	{
		if (ft_list_size(*stack_a) >= 2)
			if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
			{
				swap(stack_a);
				*commands = ft_comm_add_back((*commands), "sa");
			}
		if (ft_list_size(*stack_b) >= 2)
			if ((*stack_b)->pos - (*stack_b)->next->pos == -1)
			{
				swap(stack_b);
				*commands = ft_comm_add_back((*commands), "sb");
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
			*commands = ft_comm_add_back((*commands), "rra");
		}
		else
		{
			rotate(stack_a);
			*commands = ft_comm_add_back((*commands), "ra");
		}
	}
	if (ft_list_size(*stack_a) > 2)
	{
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
			*commands = ft_comm_add_back((*commands), "ra");
			first_two(stack_a, stack_b, commands);
		}
	}
	ret = (*stack_a)->pos;
	rotate(stack_a);
	*commands = ft_comm_add_back((*commands), "ra");
	return (ret);
}

void	push_b_while(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int last_sorted)
{
	t_list *tmp;

	tmp = ft_list_dup(*stack_a);
	if (ft_list_size(tmp) < last_sorted + 1)
		return ;
	while ((*stack_a)->pos != last_sorted + 1)
	{
		push(stack_a, stack_b);
		*commands = ft_comm_add_back((*commands), "pb");
	}
	if ((*stack_a)->pos == last_sorted + 1)
	{
		push(stack_a, stack_b);
		*commands = ft_comm_add_back((*commands), "pb");
	}
}

int		find_the_biggest_sequence(t_list *stack_b, int last_sorted)
{
	t_list	*tmp;
	int		end;

	tmp = stack_b;
	last_sorted++;
	end = last_sorted;
	while (tmp)
	{
		if (tmp->pos == end + 1)
		{
			++end;
			tmp = stack_b;
		}
		else
			tmp = tmp->next;
	}
	return (end);
}

void	if_else_push_back(t_list **stack_b, t_comm **commands,
	int end_sorted, int list_size)
{
	int list_b_pos;

	list_b_pos = find_in_list(*stack_b, end_sorted);
	if (list_b_pos > list_size / 2)
	{
		while ((*stack_b)->pos != end_sorted)
		{
			reverse_rotate(stack_b);
			*commands = ft_comm_add_back((*commands), "rrb");
		}
	}
	else
		while ((*stack_b)->pos != end_sorted)
		{
			rotate(stack_b);
			*commands = ft_comm_add_back((*commands), "rb");
		}
}

int		push_back(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int last_sorted)
{
	int	list_size;
	int	end_sorted;
	int	ret;

	if (!(*stack_b))
		return (0);
	list_size = ft_list_size(*stack_b);
	first_two(stack_a, stack_b, commands);
	end_sorted = find_the_biggest_sequence(*stack_b, last_sorted);
	ret = end_sorted;
	while (end_sorted > last_sorted)
	{
		if_else_push_back(stack_b, commands, end_sorted, list_size);
		push(stack_b, stack_a);
		*commands = ft_comm_add_back((*commands), "pa");
		end_sorted--;
	}
	return (ret - 1);
}

void	rotate_back(t_list **stack_a,
	t_comm **commands, int num)
{
	int list_a_size;
	int	where_is_one;

	where_is_one = find_in_list((*stack_a), 1);
	list_a_size = ft_list_size(*stack_a);
	if (where_is_one < list_a_size / 2)
	{
		while (num > 0)
		{
			rotate(stack_a);
			*commands = ft_comm_add_back((*commands), "ra");
			num--;
		}
	}
	else
	{
		while (num < list_a_size)
		{
			reverse_rotate(stack_a);
			*commands = ft_comm_add_back((*commands), "rra");
			num++;
		}
	}
}

int		solver(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	int	last_sorted;

	first_two(stack_a, stack_b, commands);
	last_sorted = push_while(stack_a, stack_b, commands);
	push_b_while(stack_a, stack_b, commands, last_sorted);
	last_sorted = push_back(stack_a, stack_b, commands, last_sorted);
	rotate_back(stack_a, commands, last_sorted);
	if (check_answer(*stack_a, *stack_b) == 1)
		return (1);
	return (0);
}
