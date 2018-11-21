/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_answer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:27:01 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/20 15:54:42 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_comm	*optimize_answer(t_comm *commands)
{
	t_comm	*word;

	word = NULL;
	if (!commands->next)
		return (commands);
	while (commands && commands->next)
	{
		if (check_if(commands->command, commands->next->command) == 1)
		{
			if_check_if(&commands);
			continue ;
		}
		else
			word = ft_comm_add_back(word, commands->command);
		commands = commands->next;
	}
	if (commands)
		word = ft_comm_add_back(word, commands->command);
	ft_comm_clean(&commands);
	return (word);
}
