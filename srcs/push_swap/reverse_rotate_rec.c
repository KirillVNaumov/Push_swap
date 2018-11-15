#include "push_swap.h"

int         reverse_rotate_rec(t_list *stack_a, t_list *stack_b, int set_depth, t_comm **command_list)
{
	t_list		*temp_a;
	t_list		*temp_b;

	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
	reverse_rotate(&temp_a);
	reverse_rotate(&temp_b);
	if (search(temp_a, stack_b, set_depth - 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "rra");
		return (1);
	}
	if (search(stack_a, temp_b, set_depth - 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "rrb");
		return (1);
	}	
	if (search(temp_a, temp_b, set_depth - 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "rrr");
		return (1);
	}
    return (-1);
}