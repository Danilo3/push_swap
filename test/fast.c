//
// Created by Aletha Yellin on 27/02/2020.
//

#include "libft.h"

int		main(int argc, char **argv)
{
	int		value;
	int		result;
	char 	*str;

	if (argc == 1)
		str = ft_strdup("1 2 3 4 5");
	else
		str = argv[1];
	result = ft_parse_int_str(&str, &value);
	ft_printf("res = %d, value = %d\n", result, value);
	result = ft_parse_int_str(&str, &value);
	ft_printf("res = %d, value = %d\n", result, value);
	while ((result = ft_parse_int_str(&str, &value)) > 0)
		ft_printf("res = %d, value = %d,  str = %s\n", result, value, str);
	if (result < 0)
		ft_printf("Error");
}