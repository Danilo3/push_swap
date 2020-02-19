//
// Created by Aletha Yellin on 19/02/2020.
//

#include "push_swap.h"

int		solve(t_stack *stack_a, t_stack *stack_b)
{
	t_command_list list;

	swap_x(stack_a, &list, "sa");
	swap_x(stack_b, &list, "sb");
	print_commands(&list);
	return (0);
}