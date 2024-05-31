/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyukim <siyukim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:22:35 by siyukim           #+#    #+#             */
/*   Updated: 2024/05/30 20:22:35 by siyukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_list(t_stack **stack)
{
	t_stack	*next;

	if (stack && *stack)
	{
		while ((*stack)->next)
		{
			next = (*stack)->next;
			free(*stack);
			*stack = NULL;
			*stack = next;
		}
		free(*stack);
		*stack = NULL;
	}
}

static t_stack	*create_stack(int data)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

t_stack	*create_list(int *int_temp, int size)
{
	t_stack	*head;
	t_stack	*prev;
	t_stack	*temp;
	int		i;

	i = 0;
	head = create_stack(int_temp[i]);
	if (!head)
		return (NULL);
	prev = head;
	while (++i < size)
	{
		temp = create_stack(int_temp[i]);
		if (!temp)
		{
			clean_list(&head);
			return (NULL);
		}
		prev->next = temp;
		temp->prev = prev;
		prev = temp;
	}
	return (head);
}
