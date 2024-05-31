#include "push_swap.h"

static void	three_data_sort1(t_stack **a_stack)
{
	if ((*a_stack)->next->data > (*a_stack)->next->next->data)
	{
		rra(a_stack);
		sa(a_stack);
	}
}

static void	three_data_sort2(t_stack **a_stack)
{
	if ((*a_stack)->next->data > (*a_stack)->next->next->data)
	{
		sa(a_stack);
		rra(a_stack);
	}
	else
		ra(a_stack);
}

static void	three_data_sort3(t_stack **a_stack)
{
	if ((*a_stack)->next->data < (*a_stack)->next->next->data)
		sa(a_stack);
	else
		rra(a_stack);
}

void	three_data_sort(t_stack **a_stack)
{
	if ((*a_stack)->data < (*a_stack)->next->data \
		&& (*a_stack)->data < (*a_stack)->next->next->data)
		three_data_sort1(a_stack);
	else if ((*a_stack)->data > (*a_stack)->next->data \
		&& (*a_stack)->data > (*a_stack)->next->next->data)
		three_data_sort2(a_stack);
	else
		three_data_sort3(a_stack);
}
