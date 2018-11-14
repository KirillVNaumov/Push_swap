#include "push_swap.h"

int		check_answer(t_list *stack_a, t_list *stack_b)
{
	t_list		*tmp;

	tmp = stack_a;
	if (stack_b)
		return (-1);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (-1);
		tmp = tmp->next;
	}
	return(1);
}
