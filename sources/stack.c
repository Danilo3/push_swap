//
// Created by Aletha Yellin on 18/02/2020.
//

#include "push_swap.h"
#include <stdlib.h>

void init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}


void	add_to_stack(t_stack *stack, int value)
{
	t_stack_elem *new;
	t_stack_elem *last;

	new = stack->head;
	last = new;
	while (new)
		new = new->next;
	new = (t_stack_elem*)malloc(sizeof(t_stack_elem));
	new->value = value;
	new->next = last;
	new->prev = NULL;
	stack->head = new;
	stack->size++;
}


void free_stack(t_stack *stack)
{
	t_stack_elem *e;
	t_stack_elem *next;

	e = stack->head;
	while (e)
	{
		next = e->next;
		free(e);
		e = next;
	}
}

void	print_values(t_stack *a_stack, t_stack *b_stack)
{
	t_stack_elem *a;
	t_stack_elem *b;

	a = a_stack->head;
	b = b_stack->head;
	while (a || b)
	{
		if (a && b)
		{
			ft_printf("%d\t%d\n", a->value, b->value);
			a = a->next;
			b = b->next;
		}
		else if (a)
		{
			ft_printf("%d\t\n", a->value);
			a = a->next;
		}
		else if (b)
		{
			ft_printf("\t%d\n", b->value);
			b = b->next;
		}
	}
	ft_printf("-\t-\na\tb\n");
}