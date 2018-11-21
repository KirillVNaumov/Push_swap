/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:42:12 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/20 20:06:50 by amelikia         ###   ########.fr       */
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

char	*find_s3(char *s1)
{
	if (ft_strlen(s1) == 2)
		return ("rr");
	else if (ft_strlen(s1) == 3)
		return ("rrr");
	else
		return (NULL);
}

void		remove_extra(char *s1, char *s2, t_comm **commands, t_comm **new)
{
	char	*s3;
	int		i1;
	int		i2;
	int		i;

	i1 = 0;
	i2 = 0;
	s3 = find_s3(s1);
	while (*commands && !ft_strcmp((*commands)->command, s1))
	{
		i1++;
		(*commands) = (*commands)->next;
	}
	if (!(*commands) || ft_strcmp((*commands)->command, s2))
	{
		while (i1)
		{
			*new = ft_comm_add_back(*new, s1);
			--i1;
		}
		if (*commands)
			*new = ft_comm_add_back(*new, (*commands)->command);
		return ;
	}
	while (*commands && !ft_strcmp((*commands)->command, s2))
	{
		i2++;
		(*commands) = (*commands)->next;
	}
	i1 > i2 ? (i = i1 - i2) : (i = i2 - i1);
	if (i1 > i2)
	{
		while (i)
		{
			*new = ft_comm_add_back(*new, s1);
			--i;
		}
		while (i2)
		{
			*new = ft_comm_add_back(*new, s3);
			--i2;
		}
	}
	else if (i1 < i2)
	{
		while (i1)
		{
			*new = ft_comm_add_back(*new, s3);
			--i1;
		}
		while (i)
		{
			*new = ft_comm_add_back(*new, s2);
			--i;
		}
	}
	else
	{
		while (i1)
		{
			*new = ft_comm_add_back(*new, s3);
			--i1;
		}
	}
	*new = ft_comm_add_back(*new, (*commands)->command);
}

t_comm	*remove_bitches(t_comm *commands)
{
	t_comm	*new;
	t_comm	*tmp;

	new = NULL;
	tmp = commands;
	while (commands)
	{
		if (!ft_strcmp(commands->command, "ra"))
			remove_extra("ra", "rb", &commands, &new);
		else if (!ft_strcmp(commands->command, "rb"))
			remove_extra("rb", "ra", &commands, &new);
		else if (!ft_strcmp(commands->command, "rra"))
			remove_extra("rra", "rrb", &commands, &new);
		else if (!ft_strcmp(commands->command, "rrb"))
			remove_extra("rrb", "rra", &commands, &new);
		else
			new = ft_comm_add_back(new, commands->command);
		if (commands)
			commands = commands->next;
	}
	ft_comm_clean(&tmp);
	return (new);
}

t_comm	*optimize(t_comm *commands)
{
	while (check_for_right_commnds(commands) == 0)
		commands = optimize_answer(commands);
	commands = remove_bitches(commands);
	return (commands);
}

int		find_solution(t_list **stack_a)
{
	t_list	*stack_b;
	t_comm	*tmp;
	t_comm	*commands;
	int		end;
	int		stop;

	stop = 0;
	commands = NULL;
	stack_b = NULL;
	*stack_a = list_assign_pos(*stack_a);
	end = find_the_last_number(*stack_a);
	while (1)
		if (solver(stack_a, &stack_b, &commands, end) == 1)
			break ;
	if (!commands)
		return (0);
	commands = optimize(commands);
	tmp = commands;
	while (commands)
	{
		ft_printf("%s\n", commands->command);
		commands = commands->next;
	}
	ft_comm_clean(&tmp);
	return (0);
}
