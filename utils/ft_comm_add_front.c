#include "utils.h"

t_comm	*ft_comm_add_front(t_comm *list, char *command)
{
	t_comm		*node;

	if (list == NULL)
	{
		list = (t_comm *)malloc(sizeof(t_comm));
		list->command = ft_strdup(command);
		list->next = NULL;
		return (list);
	}
	node = (t_comm *)malloc(sizeof(t_comm));
	node->next = list;
	node->command = ft_strdup(command);
	return (node);
}
