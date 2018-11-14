#include "push_swap.h"

int			search(t_list *stack_a, t_list *stack_b, int set_depth, int depth, t_comm **command_list)
{
	t_list		*temp_a;
	t_list		*temp_b;



	if (check_answer(stack_a, stack_b) == 1)
		return (1);
	if (depth > set_depth)
		return (-1);


	// temp_a = ft_list_dup(stack_a);
	// temp_b = ft_list_dup(stack_b);

	// ft_printf("Depth = %d\nStack_a:\n", depth);
	// while (temp_a)
	// {
	// 	ft_printf("%d\n", temp_a->data);
	// 	temp_a = temp_a->next;
	// }
	// ft_printf("\n");
	// ft_printf("Depth = %d\nStack_b:\n", depth);
	// while (temp_b)
	// {
	// 	ft_printf("%d\n", temp_b->data);
	// 	temp_b = temp_b->next;
	// }
	// ft_printf("\n");
	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);


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
	}	
	if (search(temp_a, temp_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "ss");
		return (1);
	}
	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);

	//PUSH

	push(&temp_b, &temp_a);
	if (search(temp_a, temp_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "pa");
		return (1);
	}
	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
	push(&temp_a, &temp_b);
	if (search(temp_a, temp_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "pb");
		return (1);
	}
	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);

	//ROTATE

	rotate(&temp_a);
	rotate(&temp_b);
	if (search(temp_a, stack_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "ra");
		return (1);
	}
	if (search(stack_a, temp_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "rb");
		return (1);
	}	
	if (search(temp_a, temp_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "rr");
		return (1);
	}
	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);

	//REVERSE ROTATE

	reverse_rotate(&temp_a);
	reverse_rotate(&temp_b);
	if (search(temp_a, stack_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "rra");
		return (1);
	}
	if (search(stack_a, temp_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "rrb");
		return (1);
	}	
	if (search(temp_a, temp_b, set_depth, depth + 1, command_list) == 1)
	{
		*command_list = ft_comm_add_front(*command_list, "rrr");
		return (1);
	}

	return (-1);
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
	while (command_list)
	{
		ft_printf("%s\n", command_list->command);
		command_list = command_list->next;
	}
}