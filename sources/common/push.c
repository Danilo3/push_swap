#include "push_swap.h"

void		push_to_stack(t_stack *stack, t_stack_elem *elem)
{
	t_stack_elem *tmp;

	tmp = stack->head;
	stack->head = elem;
	elem->next = tmp;
}

t_stack_elem	*pop_from_stack(t_stack *stack)
{
	t_stack_elem *elem;

	if (!stack->head)
		return (NULL);
	elem = stack->head;
	stack->head = stack->head->next;
	elem->next = NULL;
	return (elem);
}

int 	push_x(t_stack *stack_a, t_stack *stack_b, t_command_list *list, const char *name)
{
	t_stack_elem	*temp;

	temp = pop_from_stack(stack_a);
	if (temp)
	{
		push_to_stack(stack_b, temp);
		stack_a->size--;
		stack_b->size++;
	}
	add_command(list, name);
	return (1);
}

