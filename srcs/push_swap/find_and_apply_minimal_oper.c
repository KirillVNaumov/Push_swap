# include "push_swap.h"

int         find_last_pos(t_list *stack)
{
    if (stack == NULL)
        return (0);
    while (stack->next)
        stack = stack->next;
    return (stack->pos);
}

void        set_minimal(t_minimal *min)
{
    min->ra = 0;
    min->rb = 0;
    min->rra = 0;
    min->rrb = 0;
    min->rr = 0;
    min->rrr = 0;
    min->current_total = 2147483647;
}

void         find_minimal(t_list *stack, t_minimal *min, int pos, int id)
{
    if (id == 'a')
    {
        min->ra = count_rotate(stack, pos);
        min->rra = count_reverse_rotate(stack, pos);
    }
    else
    {
        min->rb = count_rotate(stack, pos);
        min->rrb = count_reverse_rotate(stack, pos);
    }
}

int		find_pos(t_list *stack_a, int min_max)
{
	t_list	*tmp;
    int     min;
	int		max;

	max = 0;
    min = 2147483647;
    tmp = stack_a;
    while (tmp)
    {
        if (max < tmp->pos && min_max == 1)
            max = tmp->pos;
        if (min > tmp->pos && min_max == -1)
            min = tmp->pos;
        tmp = tmp->next;
    }
    if (min_max == -1)
	    return (min);
    return (max);
}

int        right_pos_in_a(t_list *stack_a, int pos)
{
    t_list      *tmp;
    int         pos_a;

    pos_a = find_pos(stack_a, -1);
    if (pos < pos_a || pos > find_pos(stack_a, 1))
        return (pos_a);
    tmp = ft_list_dup(stack_a);
    rotate_until(&tmp, pos_a);
    while (tmp->pos < pos)
        rotate(&tmp);
    // ft_printf("       pos = %d pos in a = %d\n", pos, tmp->pos);
    pos_a = tmp->pos;
    ft_list_clean(&tmp);
    return(pos_a);
}

int         return_minimal(int n1, int n2)
{
    return (n1 > n2 ? n2 : n1);
}

void        find_total(t_minimal *min, t_comm **commands)
{
    int     total_ra_rb;
    int     total_rra_rb;
    int     total_ra_rrb;
    int     total_rra_rrb;

    total_rra_rb = min->rra + min->rb;
    total_ra_rrb = min->ra + min->rrb;
    if (min->ra > min->rb)
    {
        min->rr = min->rb;
        total_ra_rb = min->ra;
    }
    else
    {
        min->rr = min->ra;
        total_ra_rb = min->rb;
    }
    if (min->rra > min->rrb)
    {
        min->rrr = min->rrb;
        total_rra_rrb = min->rra;
    }
    else
    {
        min->rrr = min->rra;
        total_rra_rrb = min->rrb;
    }
    // ft_printf("---------------\nra/rb = %d, rra/rb = %d, ra/rrb = %d, rra/rrb = %d\n", total_ra_rb, total_rra_rb, total_ra_rrb, total_rra_rrb);
    min->current_total = return_minimal(\
    return_minimal(return_minimal(return_minimal(\
    min->current_total, total_ra_rrb), total_rra_rb), \
    total_rra_rrb), total_ra_rb);
    // ft_printf("current total = %d\n\n", min->current_total);
    if (min->current_total == total_ra_rb)
        assign_comm_ra_rb(min, commands);
    else if (min->current_total == total_rra_rb)
        assign_comm_rra_rb(min, commands);
    else if (min->current_total == total_ra_rrb)
        assign_comm_ra_rrb(min, commands);
    else if (min->current_total == total_rra_rrb)
        assign_comm_rra_rrb(min, commands);
}

void        deal_with_b(t_list **tmp, t_list *stack_b, t_minimal *min, t_list *stack_a)
{
    int     pos_a;
    t_comm  *commands;

    commands = NULL;
    set_minimal(min);
    find_minimal(stack_b, min, (*tmp)->pos, 'b');
    // ft_printf("     %d: min.rb == %d min.rrb == %d\n", (*tmp)->pos, min->rb, min->rrb);
    pos_a = right_pos_in_a(stack_a, (*tmp)->pos);
    find_minimal(stack_a, min, pos_a, 'a');
    // ft_printf("     %d: min.ra == %d min.rra == %d\n", pos_a, min->ra, min->rra);
    find_total(min, &commands);
    // ft_printf("     %d before %d - %d\n", (*tmp)->pos, pos_a, min->current_total);
    if (min->current_total < min->best_total)
    {
        min->best_pos = (*tmp)->pos;
        min->best_total = min->current_total;
        min->commands = commands;
    }
    rotate(tmp);
}

void        apply_commands(t_list **stack_a, t_list **stack_b, t_comm *commands)
{
    while (commands)
    {
        if (!ft_strcmp(commands->command, "ra"))
            rotate(stack_a);
        else if (!ft_strcmp(commands->command, "rb"))
            rotate(stack_b);
        else if (!ft_strcmp(commands->command, "rr"))
        {
            rotate(stack_a);
            rotate(stack_b);
        }
        else if (!ft_strcmp(commands->command, "rra"))
            reverse_rotate(stack_a);
        else if (!ft_strcmp(commands->command, "rrb"))
            reverse_rotate(stack_b);
        else if (!ft_strcmp(commands->command, "rrr"))
        {
            reverse_rotate(stack_a);
            reverse_rotate(stack_b);
        }
        ft_printf("%s\n", commands->command);
        commands = commands->next;
    }
    push(stack_b, stack_a);
    ft_printf("pa\n");
}

void        find_and_apply_minimal_oper(t_list **stack_a, t_list **stack_b)
{
    int         begin_b;
    t_list      *tmp;
    t_minimal   min;

    begin_b = find_last_pos(*stack_b);
    min.best_total = 2147483647;
    min.best_pos = 0;
    tmp = ft_list_dup(*stack_b);
    while (tmp->pos != begin_b && min.best_total > 2)
        deal_with_b(&tmp, *stack_b, &min, *stack_a);
    deal_with_b(&tmp, *stack_b, &min, *stack_a);

    apply_commands(stack_a, stack_b, min.commands);

    // t_list  *tmp_a;
    // t_list  *tmp_b;
    // tmp_a = ft_list_dup(*stack_a);
    // tmp_b = ft_list_dup(*stack_b);
	// ft_printf("\nStack a:\n");
	// while (tmp_a)
	// {
	// 	ft_printf("%d -- %d\n", tmp_a->data, tmp_a->if_chain);
	// 	tmp_a = tmp_a->next;
	// }
	// ft_printf("\nStack b:\n");
	// while (tmp_b)
	// {
	// 	ft_printf("%d -- %d\n", tmp_b->data, tmp_b->if_chain);
	// 	tmp_b = tmp_b->next;
	// }
    // ft_printf("\n\n");
}