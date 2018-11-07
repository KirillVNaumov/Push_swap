#include "includes/operations.h"

int main()
{
	t_list *a;
	t_list *b;

	a = NULL;
	a = ft_list_add_back(a, 1);
	a = ft_list_add_back(a, 2);
	a = ft_list_add_back(a, 3);
	a = ft_list_add_back(a, 4);
	a = ft_list_add_back(a, 5);

	b = NULL;
	b = ft_list_add_back(b, 6);
	b = ft_list_add_back(b, 7);
	b = ft_list_add_back(b, 8);



	ft_printf("a:\n");
	while (a)
	{
		ft_printf("%d\n", a->data);
		a = a->next;
	}
	ft_printf("\nb:\n");
	while (b)
	{
		ft_printf("%d\n", b->data);
		b = b->next;
	}
}
