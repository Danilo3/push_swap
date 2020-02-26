//
// Created by Aletha Yellin on 18/02/2020.
//

#include "push_swap.h"

int		push_swap()
{
	t_app	*app;
	char	*argv[] = {"lol", "1", "2", "3"};

	app = new_app();
	init_app(app, 4, argv);
	print_state(app, NULL);
	push_x(app->a, app->b, NULL, NULL);
	print_state(app, "pb");
	push_x(app->a, app->b, NULL, NULL);
	print_state(app, "pb");
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

int main()
{
	push_swap();
}
