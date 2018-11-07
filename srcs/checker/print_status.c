# include "checker.h"

void		print_status(t_list *stack_a, t_list *stack_b)
{
	int		heigth;
	int 	printed_rows;

	ft_printf("-------------------------\n");
	if (ft_list_size(stack_a) > ft_list_size(stack_b))
		heigth = ft_list_size(stack_a);
	else
		heigth = ft_list_size(stack_b);
	printed_rows = 0;
	while (heigth > printed_rows)
	{
		if ((ft_list_size(stack_a) + printed_rows) >= heigth)
		{
			ft_printf("%d ", stack_a->data);
			stack_a = stack_a->next;
		}
		else
			ft_printf("  ");
		if ((ft_list_size(stack_b) + printed_rows) >= heigth)
		{
			ft_printf("%d", stack_b->data);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
		++printed_rows;
	}
	ft_printf("- -\na b\n");
}