/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_answer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:27:01 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/19 13:19:29 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_if(t_comm **commands, t_comm **word)
{
	if (check_if_2((*commands)->command, (*commands)->next->command) == 1)
	{
		if_check_if(commands);
		*word = ft_comm_add_back((*word), "rrr");
	}
	else if (check_if_3((*commands)->command, (*commands)->next->command) == 1)
	{
		if_check_if(commands);
		*word = ft_comm_add_back((*word), "rr");
	}
	else
		*word = ft_comm_add_back((*word), (*commands)->command);
}

t_comm	*optimize_answer(t_comm *commands)
{
	t_comm	*word;

	word = NULL;
	if (!commands->next)
		return (commands);
	while (commands != NULL && commands->next)
	{
		if (check_if(commands->command, commands->next->command) == 1)
		{
			if_check_if(&commands);
			continue ;
		}
		else
			assign_if(&commands, &word);
		commands = commands->next;
	}
	if (commands)
		word = ft_comm_add_back(word, commands->command);
	return (word);
}
