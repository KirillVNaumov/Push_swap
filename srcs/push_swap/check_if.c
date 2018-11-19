/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:18:16 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/19 13:18:45 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_if(char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra")) ||
	(!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra"))
	|| (!ft_strcmp(s1, "pb") && !ft_strcmp(s2, "pa")) ||
	(!ft_strcmp(s1, "pa") && !ft_strcmp(s2, "pb")) ||
	(!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "rrb"))
	|| (!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb")))
		return (1);
	return (0);
}

int		check_if_2(char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "rrb"))
	|| (!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rra")))
		return (1);
	return (0);
}

int		check_if_3(char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rb")) ||
	(!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "ra")))
		return (1);
	return (0);
}

void	if_check_if(t_comm **commands)
{
	if ((*commands)->next)
	{
		if ((*commands)->next->next)
		{
			*commands = (*commands)->next;
			*commands = (*commands)->next;
		}
		else
			*commands = NULL;
	}
}
