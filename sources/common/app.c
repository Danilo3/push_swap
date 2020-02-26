#include "push_swap.h"
#include <stdlib.h>

t_app     *init_app(int argc, char **argv)
{
    t_app *new;

    new = ft_memalloc(sizeof(t_app));
    if (!new)
		return (new);
    new->a = init_stack();
    new->b = init_stack();
    new->cmds = ft_memalloc(sizeof(t_command_list));
    return (new);
}

void	run_app(t_app *app)

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
