#include "operations.h"

void		push(t_list **src, t_list **dst)
{
	t_list		*tmp;

	if (ft_list_size(*src) < 1)
		return ;
	tmp = *src;
	*dst = ft_list_add_front(*dst, tmp->data);
	ft_list_remove_front(src);
}