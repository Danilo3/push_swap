//
// Created by dan on 2/18/20.
//

#include "push_swap.h"
#include <stdlib.h>

int		swap_x(t_stack *stack, t_command_list *list, const char *name)
{
	int				tmp;
	t_stack_elem	*elem;

	if (stack->size == 0 || stack->size == 1)
		return (0);
	elem = stack->head;
	tmp = elem->value;
	elem->value = elem->next->value;
	elem->next->value = tmp;
	add_command(list, name);
	return (1);
}

int		pop(t_stack *stack)
{
	int value;

	if (!stack || !stack->head)
		return (0);
	value = stack->head->value;
	stack->head = stack->head->next;
	free(stack->head);
	return (value);
}