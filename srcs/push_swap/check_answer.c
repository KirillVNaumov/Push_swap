#include "push_swap.h"

int		check_answer(t_list *stack_a, t_list *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return(1);
}
