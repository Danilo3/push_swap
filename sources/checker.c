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
	t_stack stack_b;

	i = 1;
	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc == 1)
		ft_exit(NULL, "Error\n");
	while(i < argc)
	{
		v = ft_isnum(argv[i]);
		add_to_stack(&stack_a, v);
		i++;
	}
	if (check_dup(&stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		ft_exit(NULL, "Error\n");
	}
	print_values(&stack_a, &stack_b);
//	if (check_is_sorted(&stack_a, DESCENDING))
//		ft_printf("Stack a is sorted");
	free_stack(&stack_a);
	free_stack(&stack_b);
}