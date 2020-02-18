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
	stack->head->prev = (t_stack_elem*)malloc(sizeof(t_stack_elem));
	stack->head->prev->value = value;
	stack->head->prev->next = stack->head;
	stack->head->prev->prev = NULL;
}