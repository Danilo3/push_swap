//
// Created by Aletha Yellin on 19/02/2020.
//


#include "push_swap.h"

void 	exec(t_stack *stack_a, t_stack *stack_b, const char *cmd)
{
	if (ft_strcmp(cmd, "sa") == 0)
		swap_x(stack_a, NULL, NULL);
	else if (ft_strcmp(cmd, "sb") == 0)
		swap_x(stack_b, NULL, NULL);
	else if (ft_strcmp(cmd, "ss") == 0)
		swap_swap(stack_a, stack_b, NULL);
	else if (ft_strcmp(cmd, "pa") == 0)
		push_x(stack_a, stack_b, NULL, NULL);
	else if (ft_strcmp(cmd, "pb") == 0)
		push_x(stack_b, stack_a, NULL, NULL);
	else if (ft_strcmp(cmd, "ra") == 0)
		rotate_x(stack_a, NULL, NULL);
	else if (ft_strcmp(cmd, "rb") == 0)
		rotate_x(stack_b, NULL, NULL);
	else if (ft_strcmp(cmd, "rr") == 0)
		rotate_rotate(stack_a, stack_b, NULL);
	else if (ft_strcmp(cmd, "rra") == 0)
		reverse_rotate_x(stack_a, NULL, NULL);
	else if (ft_strcmp(cmd, "rrb") == 0)
		reverse_rotate_x(stack_b, NULL, NULL);
	else if (ft_strcmp(cmd, "rrr") == 0)
		reverse_rotate_rotate(stack_a, stack_b, NULL);
}

int		exec_commands(t_app *app)
{
	t_command *current;

	current = app->cmds->head;
	while (current)
	{
		exec(app->a, app->b, current->name);
		if (app->v_op == true)
			print_state(app, current->name);
		current = current->next;
	}
	return (check_is_sorted(app->a, ASCENDING) && check_is_empty(app->b));
}