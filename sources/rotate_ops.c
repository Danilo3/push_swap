//
// Created by Aletha Yellin on 19/02/2020.
//

#include "push_swap.h"

int 	rotate_x(t_stack *stack, t_command_list *list, const char *name)
{
	t_stack_elem *last;
	t_stack_elem *current;

	if (stack->size <= 1)
		return (0);
	current = stack->head;
	while (current->next)
		current = current->next;
	last = current;
	current = stack->head->next;
	last->next = stack->head;
	stack->head = current;
	last->next->next = NULL;
	add_command(list, name);
	return (1);
}

int		rotate_rotate(t_stack *stack_a, t_stack *stack_b, t_command_list *list)
{
	rotate_x(stack_a, list, NULL);
	rotate_x(stack_b, list, NULL);
	add_command(list, "rr");
	return (1);
}

int 	reverse_rotate_x(t_stack *stack, t_command_list *list, const char *name)
{
	t_stack_elem *last;
	t_stack_elem *current;
	t_stack_elem *prev;

	if (stack->size <= 1)
		return (0);
	current = stack->head;
	prev = current;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	last = current;
	current = stack->head;
	stack->head = last;
	last->next = current;
	prev->next = NULL;
	add_command(list, name);
	return (1);
}

int		reverse_rotate_rotate(t_stack *stack_a, t_stack *stack_b, t_command_list *list)
{
	reverse_rotate_x(stack_a, list, NULL);
	reverse_rotate_x(stack_b, list, NULL);
	add_command(list, "rrr");
	return (1);
}

// head -> 3 -> 2 -> 1
// head -> 1 -> 3 -> 2