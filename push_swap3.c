#include "push_swap.h"

int	biggest_data(t_stack *stack)
{
	int	max;

	max = -2147483648;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	smallest_data(t_stack *stack)
{
	int	min;

	min = 2147483647;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

void	last_change(t_stack **a_stack, int size)
{
	int	count;

	if ((*a_stack)->data != 0)
	{
		if ((*a_stack)->data < size / 2)
		{
			count = (*a_stack)->data;
			while (count--)
				rra(a_stack);
		}
		else
		{
			count = size - (*a_stack)->data;
			while (count--)
				ra(a_stack);
		}
	}
}
