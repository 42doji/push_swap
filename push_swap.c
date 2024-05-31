#include "push_swap.h"

void	push_swap2(t_stack **a, t_stack **b, int size, t_pivot *pivot)
{
	while (stack_count(*b) > 0)
	{
		if (pivot_in_stack(pivot->pivot3, size, *b))
			b_to_a(pivot->pivot3, size, a, b);
		else if (pivot_in_stack(pivot->pivot2, pivot->pivot3, *b))
			b_to_a(pivot->pivot2, pivot->pivot3, a, b);
		else if (pivot_in_stack(pivot->pivot1, pivot->pivot2, *b))
			b_to_a(pivot->pivot1, pivot->pivot2, a, b);
		else if (pivot_in_stack(0, pivot->pivot1, *b))
			b_to_a(0, pivot->pivot1, a, b);
	}
	last_change(a, size);
}

void	push_swap(t_stack **a_stack, t_stack **b_stack, int size)
{
	t_pivot	*pivot;

	pivot = get_pivot(size);
	if (!pivot)
	{
		clean_list(a_stack);
		exit(MALLOC_ERR);
	}
	while (stack_count(*a_stack) > 3)
	{
		if (pivot_in_stack(0, pivot->pivot1, *a_stack))
			a_to_b(0, pivot->pivot1, a_stack, b_stack);
		else if (pivot_in_stack(pivot->pivot1, pivot->pivot2, *a_stack))
			a_to_b(pivot->pivot1, pivot->pivot2, a_stack, b_stack);
		else if (pivot_in_stack(pivot->pivot2, pivot->pivot3, *a_stack))
			a_to_b(pivot->pivot2, pivot->pivot3, a_stack, b_stack);
		else if (pivot_in_stack(pivot->pivot3, size, *a_stack))
			a_to_b(pivot->pivot3, size, a_stack, b_stack);
	}
	three_data_sort(a_stack);
	push_swap2(a_stack, b_stack, size, pivot);
	free(pivot);
	pivot = NULL;
	clean_list(a_stack);
}

int	main(int argc, char const *argv[])
{
	static t_stack	*a_stack;
	static t_stack	*b_stack;
	int				*temp;
	char			**split;

	exception_check1(argc, argv);
	if (split_check(argv + 1))
	{
		split = ft_split(argv[1], ' ');
		temp = input_temp((const char **)split, split_word_count(split));
		argc = split_word_count(split) + 1;
		split_free(&split);
	}
	else
		temp = input_temp(argv + 1, argc - 1);
	if (!temp)
		return (MALLOC_ERR);
	list_value_change(&temp, argc - 1);
	a_stack = create_list(temp, argc - 1);
	free(temp);
	temp = NULL;
	if (!a_stack)
		return (MALLOC_ERR);
	push_swap(&a_stack, &b_stack, argc - 1);
	return (0);
}
