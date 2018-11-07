# include "checker.h"

void		check_result(t_list **stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (stack_b)
	{
		ft_printf("KO\n");
		return ;
	}
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			ft_printf("KO\n");
			return ;
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
}