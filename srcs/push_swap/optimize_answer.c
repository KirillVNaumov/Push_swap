/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_answer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:27:01 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 16:31:40 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_comm	*optimize_answer(t_comm *commands)
{
	t_comm	*word;

	word = NULL;
	while (commands->next)
	{
		if ((!ft_strcmp(commands->command, "ra") &&
		!ft_strcmp(commands->next->command, "rra")) ||
		(!ft_strcmp(commands->command, "rra") &&
		!ft_strcmp(commands->next->command, "ra"))
		|| (!ft_strcmp(commands->command, "pb") &&
		!ft_strcmp(commands->next->command, "pa")) ||
		(!ft_strcmp(commands->command, "pa") &&
		!ft_strcmp(commands->next->command, "pb")) ||
		(!ft_strcmp(commands->command, "rb") &&
		!ft_strcmp(commands->next->command, "rrb"))
		|| (!ft_strcmp(commands->command, "rrb") &&
		!ft_strcmp(commands->next->command, "rb")))
		{
			if (commands->next)
				if (commands->next->next)
				{
					commands = commands->next;
					commands = commands->next;
				}
			continue;
		}
		else if ((!ft_strcmp(commands->command, "rra") &&
		!ft_strcmp(commands->next->command, "rrb"))
		|| (!ft_strcmp(commands->command, "rrb")
		&& !ft_strcmp(commands->next->command, "rra")))
		{
			if (commands->next)
				if (commands->next->next)
				{
					commands = commands->next;
					commands = commands->next;
				}
			word = ft_comm_add_back(word, "rrr");
		}
		else
			word = ft_comm_add_back(word, commands->command);
		commands = commands->next;
	}
	word = ft_comm_add_back(word, commands->command);
	return (word);
}
