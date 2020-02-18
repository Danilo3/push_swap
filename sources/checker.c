//
// Created by Aletha Yellin on 18/02/2020.
//

#include <push_swap.h>
#include "libft.h"

int ft_isnum(const char *s)
{
	long value;

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

int main(int argc, char **argv)
{
	int i;
	int v;
	t_stack stack_a;

	i = 1;
	init_stack(&stack_a);
	if (argc == 1)
		ft_exit(NULL, "Error\n");
	while(i < argc)
	{
		v = ft_isnum(argv[i]);
		ft_printf("%d\n", v);
		i++;
	}
}