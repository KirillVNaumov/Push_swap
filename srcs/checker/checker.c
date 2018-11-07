#include "checker.h"

int			main(int argc, char **argv)
{
	int		i;
	int		flag_v;
	t_list	*stack;

	i = 1;
	flag_v = 0;
	if (!ft_strcmp(argv[i], "-v"))
	{
		flag_v = 1;
		++i;
	}
	while (i < argc)
	{

		stack = ft_list_add_back(stack, ft_atoi(argv[i++]));	//CHECK FOR INTEGER
	}
	if (read_output(&stack, flag_v) == -1)
		ft_printf("Error\n");

	// ft_printf("\n\na:\n");
	// while (stack)
	// {
	// 	ft_printf("%d\n", stack->data);
	// 	stack = stack->next;
	// }
}

// int			main(int argc, char **argv)
// {
// 	int		i;
// 	t_list	*stack;

// 	i = 1;
// 	while (i < argc)
// 		stack = ft_list_add_back(stack, ft_atoi(argv[i++]));	//CHECK FOR INTEGER
	
// 	reverse_rotate(&stack);
// 	rotate(&stack);
// 	ft_printf("a:\n");
// 	while (stack)
// 	{
// 		ft_printf("%d\n", stack->data);
// 		stack = stack->next;
// 	}
// }