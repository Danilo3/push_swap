//
// Created by Aletha Yellin on 18/02/2020.
//

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "libft.h"

#define MAX_CMD 11

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

typedef struct			s_command
{
	char				*name;
	struct s_command	*next;

}						t_command;

typedef struct			s_command_list
{
	t_command			*head;
	size_t				size;

}						t_command_list;

t_stack					*init_stack(void);

void					print_values(t_stack *a_stack, t_stack *b_stack, const char *cmd);

void					add_to_stack(t_stack *stack, int value);

void					free_stack(t_stack *stack);

int						check_dup(t_stack *stack);

int						check_is_empty(t_stack *stack);

int						check_is_sorted(t_stack *stack, t_sort_order order);

void					add_command(t_command_list *list, const char *name);

int						swap_x(t_stack *stack, t_command_list *list, const char *name);

int						swap_swap(t_stack* stack_a, t_stack *stack_b, t_command_list *list);

int						solve(t_stack *a_stack, t_stack *b_stack);

void					print_commands(t_command_list *list);

int 					push_x(t_stack *stack_a, t_stack *stack_b, t_command_list *list, const char *name);

int 					rotate_x(t_stack *stack, t_command_list *list, const char *name);

int						rotate_rotate(t_stack *stack_a, t_stack *stack_b, t_command_list *list);

int 					reverse_rotate_x(t_stack *stack, t_command_list *list, const char *name);

int						reverse_rotate_rotate(t_stack *stack_a, t_stack *stack_b, t_command_list *list);

int						exec_commands(t_stack *stack_a, t_stack *stack_b, t_command_list *list);

int						find_min(t_stack *stack);


#endif
