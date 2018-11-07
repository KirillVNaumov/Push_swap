#include "operations.h"

void		rotate(t_list **list)
{
	t_list	*node;

	if (ft_list_size(*list) < 2)
		return ;
	node = *list;
	*list = ft_list_add_back(*list, node->data);
	ft_list_remove_front(list);
}