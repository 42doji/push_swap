#include "push_swap.h"

void	pa(t_stack **a_stack, t_stack **b_stack)
{
	push(b_stack, a_stack);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_stack **a_stack, t_stack **b_stack)
{
	push(a_stack, b_stack);
	write(STDOUT_FILENO, "pb\n", 3);
}

void	sa(t_stack **stack)
{
	swap(stack);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	swap(stack);
	write(STDOUT_FILENO, "sb\n", 3);
}
