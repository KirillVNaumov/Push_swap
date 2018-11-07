#include "checker.h"

void		read_output(t_list *stack_a)
{
	t_list		*stack_b;
	char		*input;

	stack_b = NULL;
	//check_input;
	while (get_next_line(0, &input) > 0)
	{
		if (!ft_strcmp(input, "sa"))
			swap(&stack_a);
		if (!ft_strcmp(input, "sb"))
			swap(&stack_b);
		if (!ft_strcmp(input, "ss"))
		{
			swap(&stack_a);
			swap(&stack_b);
		}
		if (!ft_strcmp(input, "pa"))
			push(&stack_b, &stack_a);
		if (!ft_strcmp(input, "pb"))
			push(&stack_a, &stack_b);
		if (!ft_strcmp(input, "ra"))
			rotate(&stack_a);
		if (!ft_strcmp(input, "rb"))
			rotate(&stack_a);
		if (!ft_strcmp(input, "rr"))
		{
			rotate(&stack_a);
			rotate(&stack_b);
		}
		if (!ft_strcmp(input, "rra"))
			reverse_rotate(&stack_a);
		if (!ft_strcmp(input, "rrb"))
			reverse_rotate(&stack_a);
		if (!ft_strcmp(input, "rrr"))
		{
			reverse_rotate(&stack_a);
			reverse_rotate(&stack_b);
		}
		ft_strdel(&input);
	}
	check_result(stack_a, stack_b);
}