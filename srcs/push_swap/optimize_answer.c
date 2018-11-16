/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_answer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:27:01 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/15 17:41:51 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_if(char *str1, char *str2)
{
	if ((!ft_strcmp(str1, "ra") && !ft_strcmp(str2, "rra")) ||
	(!ft_strcmp(str1, "rra") && !ft_strcmp(str2, "ra"))
	|| (!ft_strcmp(str1, "pb") && !ft_strcmp(str2, "pa")) ||
	(!ft_strcmp(str1, "pa") && !ft_strcmp(str2, "pb")) ||
	(!ft_strcmp(str1, "rb") && !ft_strcmp(str2, "rrb"))
	|| (!ft_strcmp(str1, "rrb") && !ft_strcmp(str2, "rb")))
		return (1);
	return (0);
}

int		check_if_2(char *str1, char *str2)
{
	if ((!ft_strcmp(str1, "rra") && !ft_strcmp(str2, "rrb"))
	|| (!ft_strcmp(str1, "rrb") && !ft_strcmp(str2, "rra")))
		return (1);
	return (0);
}

void	magic_trick(t_comm **commands, t_comm **word)
{
	if (check_if((*commands)->command, (*commands)->next->command) == 1)
	{
		if ((*commands)->next)
			if ((*commands)->next->next)
			{
				(*commands) = (*commands)->next;
				(*commands) = (*commands)->next;
			}
		return ;
	}
	else if (check_if_2((*commands)->command, (*commands)->next->command) == 1)
	{
		if ((*commands)->next)
			if ((*commands)->next->next)
			{
				(*commands) = (*commands)->next;
				(*commands) = (*commands)->next;
			}
		*word = ft_comm_add_back((*word), "rrr");
	}
	else
		*word = ft_comm_add_back((*word), (*commands)->command);
}

t_comm	*optimize_answer(t_comm *commands)
{
	t_comm	*word;

	word = NULL;
	while (commands->next)
	{
		magic_trick(&commands, &word);
		commands = commands->next;
	}
	word = ft_comm_add_back(word, commands->command);
	return (word);
}
