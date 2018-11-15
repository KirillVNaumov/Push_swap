#include "push_swap.h"

// int         push_rec_pa(t_list *stack_a, t_list *stack_b, int set_depth, t_comm **command_list)
// {
//     *command_list = ft_comm_add_back(*command_list, "ss");
// 	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
// 	{
// 	    ft_comm_remove_back(command_list);
// 		return (-1);
// 	}
//     return (1);
// }

// int         push_rec_pb(t_list *stack_a, t_list *stack_b, int set_depth, t_comm **command_list)
// {
//     *command_list = ft_comm_add_back(*command_list, "ss");
// 	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
// 	{
// 	    ft_comm_remove_back(command_list);
// 		return (-1);
// 	}
//     return (1);
// }

int         push_rec(t_list *stack_a, t_list *stack_b, int set_depth, t_comm **command_list)
{    
	t_list      *temp_a;
    t_list      *temp_b;

    temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
	push(&temp_b, &temp_a);
	if (search(temp_a, temp_b, set_depth - 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "pa");
		return (1);
	}
    temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
	push(&temp_a, &temp_b);
	if (search(temp_a, temp_b, set_depth - 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "pb");
		return (1);
	}
    return (-1);
}