//
// Created by Aletha Yellin on 26/02/2020.
//
#include "push_swap.h"

int		parse_arg(t_app *app, char *arg, int *value)
{
	int		i;
	long	v;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]))
		{
			v = ft_atol(arg + i);
			if (v <= INT_MAX && v >= INT_MIN)
				*value = (int)v;
			while (ft_isdigit(arg[i]))
				i++;
			continue;
		}
		else if (ft_isalpha(arg[i]))
			exit_app(app, "Error");
		else if (ft_isspace(arg[i]))
			i++;
	}
	return (0);
}

int			parse_options(t_app *app, int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if ((ft_strcmp(argv[i], "-vc") == 0) || (ft_strcmp(argv[i], "-cv") == 0))
		{
			app->v_op = true;
			app->c_op = true;
		}
		else if (ft_strcmp(argv[i], "-c") == 0)
			app->c_op = true;
		else if (ft_strcmp(argv[i], "-v") == 0)
			app->v_op = true;
		i++;
	}
	return (1);
}