#include "push_swap.h"

int	stack_count(t_stack *stack)
{
	int	result;

	if (!stack)
		return (0);
	result = 1;
	while (stack->next)
	{
		stack = stack->next;
		result++;
	}
	return (result);
}

int	pivot_in_stack(int start, int end, t_stack *stack)
{
	while (stack)
	{
		if (start <= stack->data && stack->data < end)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_pivot	*get_pivot(int size)
{
	t_pivot	*pivot;

	pivot = (t_pivot *)malloc(sizeof(t_pivot));
	if (!pivot)
		return (NULL);
	pivot->pivot1 = (size / 4) * 1;
	pivot->pivot2 = (size / 4) * 2;
	pivot->pivot3 = (size / 4) * 3;
	return (pivot);
}

int	get_last_value(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->data);
}

void	three_input(char const *argv[])
{
	if (ft_atoi(argv[0]) < ft_atoi(argv[1]) \
		&& ft_atoi(argv[0]) < ft_atoi(argv[2]))
	{
		print_rra();
		print_sa();
	}
	else if (ft_atoi(argv[0]) > ft_atoi(argv[1]) \
		&& ft_atoi(argv[0]) > ft_atoi(argv[2]))
	{
		if (ft_atoi(argv[1]) < ft_atoi(argv[2]))
			print_ra();
		else
		{
			print_ra();
			print_sa();
		}
	}
	else
	{
		if (ft_atoi(argv[1]) < ft_atoi(argv[2]))
			print_sa();
		else
			print_rra();
	}
}
