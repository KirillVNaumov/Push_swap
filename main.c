#include "includes/operations.h"

int main()
{
	t_list *list;

	list = NULL;
	list = ft_list_add_back(list, 1);
	list = ft_list_add_back(list, 2);
	list = ft_list_add_back(list, 3);
	list = ft_list_add_back(list, 4);
	list = ft_list_add_back(list, 5);
	ft_list_remove_front(&list);
	while (list)
	{
		ft_printf("%d\n", list->data);
		list = list->next;
	}
}
