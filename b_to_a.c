#include "push_swap.h"

static int	a_cost_check(int data, t_stack *a_stack)
{
	int	cost;

	if (get_last_value(a_stack) < data && data < a_stack->data)
		return (0);
	if (biggest_data(a_stack) < data)
		return (biggest_data_input_cost(a_stack));
	if (smallest_data(a_stack) > data)
		return (smallest_data_input_cost(a_stack));
	while (a_stack->next)
	{
		if (a_stack->data < a_stack->next->data)
			if (a_stack->data < data && data < a_stack->next->data)
				break ;
		a_stack = a_stack->next;
	}
	if (top_or_bottom2(a_stack))
		cost = go_to_top_cost(a_stack) + 1;
	else
		cost = go_to_bottom_cost(a_stack) - 1;
	return (cost);
}

static int	b_to_a_cost_check(int start, int end, t_stack *a, t_stack *b)
{
	int	data;
	int	min_cost;
	int	current_cost;

	min_cost = 2147483647;
	while (b)
	{
		if (start <= b->data && b->data < end)
		{
			if (top_or_bottom2(b))
				current_cost = a_cost_check(b->data, a) + go_to_top_cost(b);
			else
				current_cost = a_cost_check(b->data, a) + go_to_bottom_cost(b);
			if (current_cost < min_cost)
			{
				min_cost = current_cost;
				data = b->data;
			}
		}
		b = b->next;
	}
	return (data);
}

static void	b_to_a_a_stack_move2(int cost, t_stack *temp, t_stack **a_stack)
{
	if (top_or_bottom2(temp))
		while (cost--)
			ra(a_stack);
	else
		while (cost--)
			rra(a_stack);
}

static void	b_to_a_a_stack_move(int data, int cost, t_stack **a_stack)
{
	const t_stack	*temp = *a_stack;

	if (get_last_value((t_stack *)temp) < data && data < temp->data)
		return ;
	while (temp->next)
	{
		if (data > biggest_data(*a_stack))
			if (temp->data == biggest_data(*a_stack))
				break ;
		if (data < smallest_data(*a_stack))
		{
			if (temp->data == smallest_data(*a_stack))
			{
				temp = temp->prev;
				if (temp == NULL)
					return ;
				break ;
			}
		}
		if (temp->data < temp->next->data)
			if (temp->data < data && data < temp->next->data)
				break ;
		temp = temp->next;
	}
	b_to_a_a_stack_move2(cost, (t_stack *)temp, a_stack);
}

void	b_to_a(int start, int end, t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	int		data;
	int		cost;

	temp = *b_stack;
	data = b_to_a_cost_check(start, end, *a_stack, *b_stack);
	b_to_a_a_stack_move(data, a_cost_check(data, *a_stack), a_stack);
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
		push_top(a_stack, b_stack, cost, 0);
	else
		push_bottom(a_stack, b_stack, cost, 0);
}
