//
// Created by Aletha Yellin on 19/02/2020.
//

#include "push_swap.h"

int		solve(t_stack *stack_a, t_stack *stack_b)
{
	t_command_list list;

	list.head = NULL;

	push_x(stack_a, stack_b, &list, "pb");
	push_x(stack_a, stack_b, &list, "pb");
	print_values(stack_a, stack_b);
	print_commands(&list);
	return (0);
}