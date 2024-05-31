#include "push_swap.h"

static int	a_to_b_cost_check(int start, int end, t_stack *a_stack)
{
	int	data;
	int	min_cost;
	int	current_cost;

	min_cost = 2147483647;
	while (a_stack)
	{
		if (start <= a_stack->data && a_stack->data < end)
		{
			if (top_or_bottom(a_stack))
				current_cost = go_to_top_cost(a_stack);
			else
				current_cost = go_to_bottom_cost(a_stack);
			if (current_cost < min_cost)
			{
				min_cost = current_cost;
				data = a_stack->data;
			}
		}
		a_stack = a_stack->next;
	}
	return (data);
}

void	a_to_b(int start, int end, t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	int		data;
	int		cost;

	temp = *a_stack;
	data = a_to_b_cost_check(start, end, *a_stack);
	while (temp)
	{
		if (data == temp->data)
			break ;
		temp = temp->next;
	}
	if (top_or_bottom(temp))
		cost = go_to_top_cost(temp);
	else
		cost = go_to_bottom_cost(temp);
	if (top_or_bottom(temp))
		push_top(a_stack, b_stack, cost, 1);
	else
		push_bottom(a_stack, b_stack, cost, 1);
}
