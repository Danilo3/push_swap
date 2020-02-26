#include "push_swap.h"

int 	push_x(t_stack *stack_a, t_stack *stack_b, t_command_list *list, const char *name)
{
	t_stack_elem	*temp;
	t_stack_elem	*temp2;

	if (stack_a->size == 0)
		return (0);
	if (stack_b->head)
		temp = stack_b->head;
	else
		temp = NULL;
	temp2 = stack_a->head->next;
	stack_b->head = stack_a->head;
	stack_b->head->next = temp;
	stack_a->head = temp2;
	stack_a->size--;
	stack_b->size++;
	add_command(list, name);
	return (1);
}