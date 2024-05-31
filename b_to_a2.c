#include "push_swap.h"

int	biggest_data_input_cost(t_stack *a_stack)
{
	int		cost;
	t_stack	*temp;

	temp = a_stack;
	while (temp->next)
	{
		if (temp->data == biggest_data(a_stack))
			break ;
		temp = temp->next;
	}
	if (top_or_bottom2(temp))
		cost = go_to_top_cost(temp) + 1;
	else
		cost = go_to_bottom_cost(temp) - 1;
	return (cost);
}

int	smallest_data_input_cost(t_stack *a_stack)
{
	int		cost;
	t_stack	*temp;

	temp = a_stack;
	while (temp->next)
	{
		if (temp->data == smallest_data(a_stack))
			break ;
		temp = temp->next;
	}
	temp = temp->prev;
	if (temp == NULL)
		return (0);
	if (top_or_bottom2(temp))
		cost = go_to_top_cost(temp) + 1;
	else
		cost = go_to_bottom_cost(temp) - 1;
	return (cost);
}
