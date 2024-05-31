#include "push_swap.h"

void	ra(t_stack **stack)
{
	rotate(stack);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	write(STDOUT_FILENO, "rrb\n", 4);
}
