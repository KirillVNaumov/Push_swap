#include "utils.h"

int		ft_comm_size(t_comm *root)
{
	int		i;
	t_comm	*entity;

	i = 1;
	if (!root)
		return (0);
	if (root)
	{
		entity = root;
		while (entity)
			(entity = entity->next) && i++;
	}
	return (i);
}
