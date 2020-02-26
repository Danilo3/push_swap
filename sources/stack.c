/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:48:46 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/26 02:48:50 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack		*init_stack()
{
	t_stack *new;

	new = ft_memalloc(sizeof(t_stack));
	new->head = NULL;
	new->size = 0;
	return (new);
}

void		add_to_stack(t_stack *stack, int value)
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
	if(new->next)
		new->id = new->next->value;
	else
		new->id = 0;
	stack->head = new;
	stack->size++;
}

void		free_stack(t_stack *stack)
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

void		print_header(const char *cmd)
{
	if (!cmd)
		ft_putstr("Init a and b: \n");
	else
		ft_printf("Exec: %s\n", cmd);
	ft_putstr("------A-----+-----B------\n");
}

void		print_values(t_stack *a_stack, t_stack *b_stack, const char *cmd)
{
	t_stack_elem *a;
	t_stack_elem *b;

	a = a_stack->head;
	b = b_stack->head;
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
