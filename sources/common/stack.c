/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:48:46 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/26 10:50:07 by dan              ###   ########.fr       */
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
	new->tail = NULL;
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
	new = ft_memalloc(sizeof(t_stack_elem));
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

