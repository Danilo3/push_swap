//
// Created by Aletha Yellin on 19/02/2020.
//

#include "push_swap.h"
#include <stdlib.h>

static char	*g_commands[MAX_CMD] = {
		"sa", "sb", "ss", "pa",
		"pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"
};

int		is_right_command(const char *cmd)
{
	int i;

	i = 0;
	while (i < MAX_CMD)
	{
		if (ft_strcmp(cmd, g_commands[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int			run_commands(t_app *app)
{
	char		*cmd;

	if (app->v_op == true)
		print_state(app, NULL);
	while (get_next_line(0, &cmd) > 0)
	{
		if (is_right_command(cmd))
			add_command(app->cmds, cmd);
		else
			return (0);
		free(cmd);
	}
	free(cmd);
	if (exec_commands(app))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}

void		add_command(t_command_list *list, const char *name)
{
	t_command *new;
	t_command *current;

	if (!name || !list)
		return ;
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

void		walk_commands(t_command_list *list, t_bool to_print, t_bool to_free)
{
	t_command *current;
	t_command *next;

	current = list->head;
	while (current)
	{
		if(to_print)
			ft_printf("%s\n", current->name);
		if(to_free)
			free(current->name);
		next = current->next;
		if (to_free)
			free(current);
		current = next;
	}
}