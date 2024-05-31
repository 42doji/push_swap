#include "push_swap.h"

void	push_top(t_stack **a_stack, t_stack **b_stack, int cost, int is_a)
{
	while (cost--)
	{
		if (is_a)
			ra(a_stack);
		else
			rb(b_stack);
	}
	if (is_a)
		pb(a_stack, b_stack);
	else
		pa(a_stack, b_stack);
}

void	push_bottom(t_stack **a, t_stack **b, int cost, int is_a)
{
	while (cost--)
	{
		if (is_a)
			rra(a);
		else
			rrb(b);
	}
	if (is_a)
		pb(a, b);
	else
		pa(a, b);
}
