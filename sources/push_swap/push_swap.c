//
// Created by Aletha Yellin on 18/02/2020.
//

#include "push_swap.h"

int		push_swap()
{
	ft_printf("Hello world");

	return (0);
}

int		find_min(t_stack *stack)
{
	int				id;
	int 			min;
	t_stack_elem 	*elem;

	elem = stack->head;
	min = stack->head->value;
	id = -1;
	while (elem)
	{
		if (min >= elem->value)
		{
			min = elem->value;
			id = elem->id;
		}
		elem = elem->next;
	}
	return (id);
}

//int main()
//{
//	push_swap();
//}
