//
// Created by dan on 2/18/20.
//

#include "push_swap.h"

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

int		swap_swap(t_stack* stack_a, t_stack *stack_b, t_command_list *list)
{
	swap_x(stack_a, list, NULL);
	swap_x(stack_b, list, NULL);
	add_command(list , "ss");
	return (1);
}
