//
// Created by Aletha Yellin on 26/02/2020.
//

#include "push_swap.h"

void		print_header(const char *cmd)
{
	if (!cmd)
		ft_putstr("Init a and b: \n");
	else
		ft_printf("Exec: %s\n", cmd);
	ft_putstr("------A-----+-----B------\n");
}

void		print_state(t_app *app, const char *cmd)
{
	t_stack_elem *a;
	t_stack_elem *b;

	a = app->a->head;
	b = app->b->head;
	print_header(cmd);
	while (a || b)
	{
		if (a && b)
			ft_printf("|%11d|%11d|\n", a->value, b->value);
		else if (a)
			ft_printf("|%11d|%11c|\n", a->value, ' ');
		else if (b)
			ft_printf("|%11c|%11d|\n", ' ', b->value);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_putstr("------------+------------\n");
}