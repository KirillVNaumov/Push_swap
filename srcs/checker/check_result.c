# include "checker.h"

void		check_result(t_list *stack_a, t_list *stack_b)
{
	int check_for_wrong;

	if (stack_b)
	{
		ft_printf("error\n");
		return ;
	}
	check_for_wrong = 0;
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			check_for_wrong++;
		stack_a = stack_a->next;
	}
	if (check_for_wrong > 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}
