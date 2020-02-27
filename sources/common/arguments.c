/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:30:49 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/27 00:30:58 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 **  parse str returns 1 if was value, 0 if was error
*/

int         parse_int_arg(char *arg, int *value)
{
    long    long_value;

    while (ft_isspace(*arg))
        arg++;
    if (ft_isdigit(*arg))
    {
        long_value = ft_atol(arg);
        if (long_value >= INT_MIN && long_value <= INT_MIN)
            return (*value = (int) long_value);
    }
    return (0);
}


void		parse_values(t_app *app, int argc, char **argv)
{
	int		i;
	size_t	j;
	int		value;
	int		is_num;

	i = 1 + app->v_op + app->c_op;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]))
			{
				is_num = check_is_num(argv[i] + j, &value);
				while (ft_isdigit(argv[i][j]))
					j++;
				if ((ft_isspace(argv[i][j]) || argv[i][j] == '\0') && is_num)
				{
					add_to_stack(app->a, value);
					continue;
				}
			}
			else if (ft_isalpha(argv[i][j]))
				exit_app(app, "Error");
			j++;
		}
		i++;
	}
}

void		parse_options(t_app *app, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_isdigit(argv[i][0]))
			return ;
		if ((ft_strcmp(argv[i], "-vc") == 0) ||
		(ft_strcmp(argv[i], "-cv") == 0))
		{
			app->v_op++;
			app->c_op++;
		}
		else if (ft_strcmp(argv[i], "-c") == 0)
			app->c_op++;
		else if (ft_strcmp(argv[i], "-v") == 0)
			app->v_op++;
		i++;
	}
}
