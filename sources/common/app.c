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
	if (argc == 1)
		exit_app(app, "Error");
	parse_options(app, argc, argv);
	parse_values(app, argc, argv);
}

void	run_app(t_app *app)
{
	if (check_is_dup(app->a) || !run_commands(app))
		exit_app(app, "Error");
}
