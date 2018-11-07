#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"

typedef struct		s_list
{
	int				data;
	struct s_list 	*next;
}					t_list;


int					ft_list_size(t_list *root);
t_list				*ft_list_add_back(t_list *list, int data);
t_list				*ft_list_add_front(t_list *list, int data);
void				ft_list_clean(t_list **list);
t_list				*ft_list_dup(t_list *list);
t_list				*ft_list_remove_back(t_list *list);
t_list				*ft_list_remove_front(t_list *list);

#endif