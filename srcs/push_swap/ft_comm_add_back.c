
#include "push_swap.h"

t_comm	*ft_comm_add_back(t_comm *list, char *command)
{
	t_comm		*begining;
	t_comm		*node;
	char		*str;

	if (list == NULL)
	{
		list = (t_comm *)malloc(sizeof(t_comm));
		str = ft_strdup(command);
		list->command = str;
		list->next = NULL;
		return (list);
	}
	node = (t_comm *)malloc(sizeof(t_comm));
	begining = list;
	node->next = NULL;
	str = ft_strdup(command);
	node->command = str;
	while (list->next)
		list = list->next;
	list->next = node;
	return (begining);
}
