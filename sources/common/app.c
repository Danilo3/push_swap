#include "push_swap.h"
#include <stdlib.h>

void    destroy_app(t_app *app)
{
	free_stack(app->a);
	free_stack(app->b);
	walk_commands(app->cmds, false, true);
	free(app);
}

void	exit_app(t_app *app, const char *msg)
{
	if (app)
		destroy_app(app);
	if(msg)
		ft_putendl(msg);
	exit(0);
}

t_app     *new_app(void)
{
    t_app	*new;

    new = ft_memalloc(sizeof(t_app));
    if (!new)
		exit_app(new, "Error");
    new->a = init_stack();
    new->b = init_stack();
    new->cmds = ft_memalloc(sizeof(t_command_list));
    return (new);
}

void	init_app(t_app *app, int argc, char **argv)
{
	int		i;
	int 	value;

	i = 1;
	if (argc == 1)
		exit_app(app, "Error");
	i += parse_options(app, argc, argv);
	while (i < argc)
	{
		parse_arg(app, argv[i], &value);
		add_to_stack(app->a, value);
		i++;
	}
}

void	run_app(t_app *app)
{
	if (!run_commands(app))
		exit_app(app, "Error");
}
