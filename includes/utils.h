/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:36:45 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/09 11:37:15 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"

# define RED "\x1B[31m"
# define BLUE "\x1B[34m"
# define WHITE "\x1B[39m"

typedef struct		s_list
{
	int				data;
	int				pos;
	struct s_list	*next;
}					t_list;
int					ft_list_size(t_list *root);
t_list				*ft_list_add_back(t_list *list, int data);
t_list				*ft_list_add_front(t_list *list, int data);
void				ft_list_clean(t_list **list);
t_list				*ft_list_dup(t_list *list);
t_list				*ft_list_ndup(t_list *list, int size);
void				ft_list_remove_back(t_list **list);
void				ft_list_remove_front(t_list **list);
int					find_max_length(t_list *list);
t_list				*list_assign_pos(t_list *stack);

#endif
