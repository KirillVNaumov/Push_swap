#include "push_swap.h"

int         swap_rec_sa(t_list *stack_a, t_list *stack_b, int set_depth, t_comm **command_list)
{
	if (search(stack_a, stack_b, set_depth - 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "sa");
		return (1);
	}
    return (-1);
}

int         swap_rec_sb(t_list *stack_a, t_list *stack_b, int set_depth, t_comm **command_list)
{
	if (search(stack_a, stack_b, set_depth - 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "sb");
		return (1);
    }
    return (-1);
}

int         swap_rec_ss(t_list *stack_a, t_list *stack_b, int set_depth, t_comm **command_list)
{
	if (search(stack_a, stack_b, set_depth - 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "ss");
		return (1);
	}
    return (-1);
}

int         swap_rec(t_list *stack_a, t_list *stack_b, int set_depth, t_comm **command_list)
{
	swap(&stack_a);
    if (swap_rec_sa(stack_a, stack_b, set_depth, command_list) == 1)
        return (1);
    swap(&stack_a);
    swap(&stack_b);
    if (swap_rec_sb(stack_a, stack_b, set_depth, command_list) == 1)
        return (1);
    swap(&stack_a);    
    if (swap_rec_ss(stack_a, stack_b, set_depth, command_list) == 1)
        return (1);
    return (-1);
}