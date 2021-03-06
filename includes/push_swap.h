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
	t_stack_elem		*tail;
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


typedef struct          s_app
{
    t_stack			*a;
    t_stack			*b;
    t_command_list	*cmds;
    int				v_op;
    int 			c_op;
}                       t_app;


t_app					*new_app(void);

void					init_app(t_app *app, int argc, char **argv);

void					run_app(t_app *app);

void					destroy_app(t_app *app);

t_stack					*init_stack(void);

void					exit_app(t_app *app, const char *msg);

void					walk_commands(t_command_list *list, t_bool to_print, t_bool to_free);

int						run_commands(t_app *app);

void					parse_values(t_app *app, int argc, char **argv);

void					parse_options(t_app *app, int argc, char **argv);

void					print_state(t_app *app, const char *cmd);

void					add_to_stack(t_stack *stack, int value);

void					free_stack(t_stack *stack);

int						check_is_dup(t_stack *stack);

int						check_is_empty(t_stack *stack);

int						check_is_num(const char *arg, int *value);

int						check_is_sorted(t_stack *stack, t_sort_order order);

void					add_command(t_command_list *list, const char *name);

int						swap_x(t_stack *stack, t_command_list *list, const char *name);

int						swap_swap(t_stack* stack_a, t_stack *stack_b, t_command_list *list);

int 					push_x(t_stack *stack_a, t_stack *stack_b, t_command_list *list, const char *name);

int 					rotate_x(t_stack *stack, t_command_list *list, const char *name);

int						rotate_rotate(t_stack *stack_a, t_stack *stack_b, t_command_list *list);

int 					reverse_rotate_x(t_stack *stack, t_command_list *list, const char *name);

int						reverse_rotate_rotate(t_stack *stack_a, t_stack *stack_b, t_command_list *list);

int						exec_commands(t_app *app);

int						find_min(t_stack *stack);

#endif
