#include "utils.h"

void			ft_comm_remove_back(t_comm **list)
{
	t_comm		*tmp;
	t_comm		*node;

	if (*list == NULL)
		return ;
	if (ft_comm_size(*list) == 1)
	{
        free((*list)->command);
		free(*list);
		*list = NULL;
		return ;
	}
	node = *list;
	while (node->next->next)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
    free(tmp->command);
	free(tmp);
}
