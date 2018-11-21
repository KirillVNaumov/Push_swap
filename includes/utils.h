/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:36:45 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/19 15:44:13 by amelikia         ###   ########.fr       */
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
typedef struct		s_comm
{
	char			*command;
	struct s_comm	*next;
}					t_comm;
int					ft_list_size(t_list *root);
t_list				*ft_list_add_back(t_list *list, int data, int pos);
t_list				*ft_list_add_front(t_list *list, int data, int pos);
void				ft_list_clean(t_list **list);
t_list				*ft_list_dup(t_list *list);
t_list				*ft_list_ndup(t_list *list, int size);
void				ft_list_remove_back(t_list **list);
void				ft_list_remove_front(t_list **list);
int					find_max_length(t_list *list);
t_list				*list_assign_pos(t_list *stack);
int					add_to_list(int i, int argc, char **argv, t_list **stack);
t_comm				*ft_comm_add_front(t_comm *list, char *command);
t_comm				*ft_comm_add_back(t_comm *list, char *command);
void				ft_comm_remove_back(t_comm **list);
int					ft_comm_size(t_comm *root);
int					find_in_list(t_list *root, int num);
void				ft_comm_clean(t_comm **comm);

#endif
