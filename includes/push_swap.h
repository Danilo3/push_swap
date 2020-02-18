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

typedef enum			e_sort_order
{
	DESCENDING,
	ASCENDING
}						t_sort_order;

void					init_stack(t_stack *stack);

void					print_values(t_stack *a_stack, t_stack *b_stack);

void					add_to_stack(t_stack *stack, int value);

void					free_stack(t_stack *stack);

int						check_dup(t_stack *stack);

int						check_is_sorted(t_stack *stack, t_sort_order order);


#endif //PUSH_SWAP_PUSH_SWAP_H
