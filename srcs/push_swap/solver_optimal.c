#include "push_swap.h"

int			search(t_list *stack_a, t_list *stack_b, int set_depth, t_comm **command_list)
{
    t_list      *temp_a;
    t_list      *temp_b;

	if (check_answer(stack_a, stack_b) == 1)
		return (1);
	if (set_depth == -1)
		return (-1);
    temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
    if (swap_rec(temp_a, temp_b, set_depth, command_list) == 1)
        return (1);
    temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
    if (push_rec(temp_a, temp_b, set_depth, command_list) == 1)
        return (1);
    temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
    if (rotate_rec(temp_a, temp_b, set_depth, command_list) == 1)
        return (1);
    temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
    if (reverse_rotate_rec(temp_a, temp_b, set_depth, command_list) == 1)
        return (1);
	return (-1);
}