#include "operations.h"

void		push(t_list *src, t_list *dst)
{
	if (ft_list_size(src) < 1)
		return ;
	dst = ft_list_add_front(dst, src->data);
	src = ft_list_remove_front(src);
}