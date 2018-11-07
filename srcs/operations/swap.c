#include "operations.h"

void		swap(t_list *list)
{
	t_list		*elem1;
	t_list		*elem2;
	int			tmp;

	if (ft_list_size(list) < 2)
		return ;
	elem1 = list;
	elem2 = elem1->next;
	tmp = elem1->data;
	elem1->data = elem2->data;
	elem2->data = tmp;
}