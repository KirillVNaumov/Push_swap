# include "push_swap.h"

int			count_reverse_rotate(t_list *stack, int pos)
{
	int		count;
	t_list	*temp;

	temp = ft_list_dup(stack);
	count = 0;
	while (temp->pos != pos)
	{
		reverse_rotate(&temp);
		++count;
	}
	ft_list_clean(&temp);
	return (count);
}

int			count_rotate(t_list *stack, int pos)
{
	int		count;
	t_list	*temp;

	temp = ft_list_dup(stack);
	count = 0;
	while (temp->pos != pos)
	{
		rotate(&temp);
		++count;
	}
	ft_list_clean(&temp);
	return (count);
}

void			reverse_rotate_until(t_list **stack, int pos)
{
	while ((*stack)->pos != pos)
		reverse_rotate(stack);
}

void			rotate_until(t_list **stack, int pos)
{
	while ((*stack)->pos != pos)
		rotate(stack);
}