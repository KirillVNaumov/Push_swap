#include "utils.h"

void	ft_comm_clean(t_comm **comm)
{
	t_comm *node;

	if (*comm == NULL)
		return ;
	node = *comm;
	if (node->next)
		ft_comm_clean(&node->next);
	free((*comm)->command);
    free(*comm);
}
