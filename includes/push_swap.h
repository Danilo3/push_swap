//
// Created by Aletha Yellin on 18/02/2020.
//

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "libft.h"

typedef struct			s_stack_elem
{
	int					value;
	int					id;
	struct s_stack_elem	*next;
	struct s_stack_elem	*prev;

}						t_stack_elem;


typedef struct			s_stack
{
	t_stack_elem		*head;
	size_t				size;
}						t_stack;

void init_stack(t_stack *stack);

#endif //PUSH_SWAP_PUSH_SWAP_H
