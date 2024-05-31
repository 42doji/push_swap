#include "push_swap.h"

void	push(t_stack **top1, t_stack **top2)
{
	t_stack	*prev_top1;
	t_stack	*prev_top2;

	if (*top2 == NULL)
	{
		prev_top1 = (*top1)->next;
		*top2 = *top1;
		(*top2)->next = NULL;
		*top1 = prev_top1;
		(*top1)->prev = NULL;
	}
	else
	{
		prev_top1 = (*top1)->next;
		prev_top2 = *top2;
		*top2 = *top1;
		(*top2)->next = prev_top2;
		prev_top2->prev = *top2;
		*top1 = prev_top1;
		if (*top1)
			(*top1)->prev = NULL;
	}
}

void	swap(t_stack **stack)
{
	*stack = (*stack)->next;
	(*stack)->prev->next = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	rotate(t_stack **stack)
{
	t_stack	*bottom;

	bottom = *stack;
	while (bottom->next)
		bottom = bottom->next;
	*stack = (*stack)->next;
	bottom->next = (*stack)->prev;
	(*stack)->prev->prev = bottom;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*bottom;

	bottom = *stack;
	while (bottom->next)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	bottom->prev = NULL;
	bottom->next = *stack;
	(*stack)->prev = bottom;
	*stack = bottom;
}
