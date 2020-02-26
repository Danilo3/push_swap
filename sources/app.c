#include "push_swap.h"

t_app     *init_app(void)
{
    t_app *new;

    new = ft_memalloc(sizeof(t_app));
    new->a = init_stack();
    new->b = init_stack();
    return (new);
}

void    free_app(t_app *app)
{
    free_stack(new->a);
    free_stack(new->b);
    free(app);
}
