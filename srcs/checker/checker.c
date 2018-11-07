#include "checker.h"

int			main(int argc, char **argv)
{
	int		i;
	t_list	*stack;

	i = 1;
	while (i < argc)
		stack = ft_list_add_back(stack, ft_atoi(argv[i++]));	//CHECK FOR INTEGER
	
	read_output(stack);

	ft_printf("a:\n");
	while (stack)
	{
		ft_printf("%d\n", stack->data);
		stack = stack->next;
	}
}