#include "push_swap.h"

int	go_to_top_cost(t_stack *stack)
{
	int	cost;

	cost = 0;
	while (stack->prev)
	{
		stack = stack->prev;
		cost++;
	}
	return (cost);
}

int	go_to_bottom_cost(t_stack *stack)
{
	int	cost;

	cost = 1;
	while (stack->next)
	{
		stack = stack->next;
		cost++;
	}
	return (cost);
}

int	top_or_bottom(t_stack *stack)
{
	t_stack	*top;
	t_stack	*bottom;
	int		top_cost;
	int		bottom_cost;

	top = stack;
	bottom = stack;
	top_cost = 0;
	bottom_cost = 1;
	while (top->prev)
	{
		top = top->prev;
		top_cost++;
	}
	while (bottom->next)
	{
		bottom = bottom->next;
		bottom_cost++;
	}
	if (top_cost <= bottom_cost)
		return (1);
	else
		return (0);
}

int	top_or_bottom2(t_stack *stack)
{
	t_stack	*top;
	t_stack	*bottom;
	int		top_cost;
	int		bottom_cost;

	top = stack;
	bottom = stack;
	top_cost = 1;
	bottom_cost = 0;
	while (top->prev)
	{
		top = top->prev;
		top_cost++;
	}
	while (bottom->next)
	{
		bottom = bottom->next;
		bottom_cost++;
	}
	if (top_cost <= bottom_cost)
		return (1);
	else
		return (0);
}
