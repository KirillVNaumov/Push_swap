#include "push_swap.h"

int         check_last_comm(t_comm *list, char *command)
{
    if (list == NULL)
        return (-1);
    while (list->next)
        list = list->next;
    if (!ft_strcmp(list->command, command))
        return (1);
    return (-1);
}