/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 04:57:07 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/26 10:50:05 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

char	*g_commands[MAX_CMD] = {
	"sa", "sb", "ss", "pa",
	"pb", "ra", "rb", "rr",
	"rra", "rrb", "rrr"
};

int		ft_isnum(const char *s)
{
	long	value;

	value = ft_atol(s);
	if (value != 0 && value >= INT_MIN && value <= INT_MAX)
		return ((int)value);
	while (s)
	{
		if (!ft_isdigit(*s))
			ft_exit(NULL, "Error\n");
		s++;
	}
	return (0);
}

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

int		check_commands(t_stack *stack_a, t_stack *stack_b)
{
	t_command_list	list;
	char			*cmd;

	list.head = NULL;
	print_values(stack_a, stack_b, NULL);
	while (get_next_line(0, &cmd) > 0)
	{
		if (is_right_command(cmd))
			add_command(&list, cmd);
		else
			return (0);
		free(cmd);
	}
	free(cmd);
	if (exec_commands(stack_a, stack_b, &list))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		v;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	stack_a = init_stack();
	stack_b = init_stack();
	if (argc == 1)
		ft_exit(NULL, "Error\n");
	while (i < argc)
	{
		v = ft_isnum(argv[i]);
		add_to_stack(stack_a, v);
		i++;
	}
	if (check_dup(stack_a) || !check_commands(stack_a, stack_b))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		ft_exit(NULL, "Error\n");
	}
	free_stack(stack_a);
	free_stack(stack_b);
}
