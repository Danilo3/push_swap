//
// Created by Aletha Yellin on 19/02/2020.
//

#include "push_swap.h"
#include <stdlib.h>

void		add_command(t_command_list *list, const char *name)
{
	t_command *new;
	t_command *current;

	new = (t_command*)malloc(sizeof(t_command));
	new->name = ft_strdup(name);
	new->next = NULL;
	current = list->head;
	if (!current)
	{
		list->head = new;
		return;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}

void		print_commands(t_command_list *list)
{
	t_command *current;
	t_command *next;

	current = list->head;
	while (current)
	{
		ft_printf("%s\n", current->name);
		free(current->name);
		next = current->next;
		free(current);
		current = next;
	}
}