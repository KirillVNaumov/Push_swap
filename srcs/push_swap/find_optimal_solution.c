#include "push_swap.h"

int			search(t_list *stack_a, t_list *stack_b, int set_depth, int depth, t_comm **command_list)
{
	t_list		*temp_a;
	t_list		*temp_b;

	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
	if (check_answer(stack_a, stack_b) == 1)
		return (1);
	if (depth > set_depth)
		return (-1);
	
	//SWAP

	swap(&temp_a);
	swap(&temp_b);
	if (search(temp_a, stack_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "sa");
		return (1);
	}
	if (search(stack_a, temp_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "sb");
		return (1);
	}	if (search(temp_a, temp_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "ss");
		return (1);
	}
	swap(&temp_a);
	swap(&temp_b);

	//PUSH
	return (0);
}

void		find_optimal_solution(t_list *stack_a)
{
	int			set_depth;
	t_comm		*command_list;
	t_list		*stack_b;

	set_depth = 1;
	command_list = NULL;
	stack_b = NULL;
	while (search(stack_a, stack_b, set_depth, 1, &command_list) == -1)
	{
		set_depth++;
		command_list = NULL;
		stack_b = NULL;
	}
}