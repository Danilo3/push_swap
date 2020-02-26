//
// Created by dan on 2/18/20.
//

#include "push_swap.h"

int		check_dup(t_stack *stack)
{
	t_stack_elem *current_i;
	t_stack_elem *current_j;

	current_i = stack->head;
	while (current_i)
	{
		current_j = current_i->next;
		while (current_j)
		{
			if (current_i->value == current_j->value)
				return (1);
			current_j = current_j->next;
		}
		current_i = current_i->next;
	}
	return (0);
}

int		check_is_empty(t_stack *stack)
{
	if (!stack || stack->head == NULL)
		return (1);
	return (0);
}

int		check_is_sorted(t_stack *stack, t_sort_order order)
{
	t_stack_elem	*current;
	int 			prev_value;

	if(!stack->head)
		return (0);
	current = stack->head->next;
	prev_value = stack->head->value;
	while(current)
	{
		if (order == ASCENDING && prev_value > current->value)
			return (0);
		if (order == DESCENDING && prev_value < current->value)
			return (0);
		prev_value = current->value;
		current = current->next;
	}
	return (1);
}