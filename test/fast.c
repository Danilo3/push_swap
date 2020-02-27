//
// Created by Aletha Yellin on 27/02/2020.
//

#include "libft.h"

int		parse_int_arg(char **arg, int *value)
{
	long	long_value;
	char	*str;

	str = *arg;
	if (!str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (ft_isdigit(*str) || *str == '-')
	{
		long_value = ft_atol(str);
		str += (*str == '-' ? 1 : 0);
		while (ft_isdigit(*str))
			str++;
		*arg = str;
		if (long_value >= INT_MIN && long_value <= INT_MAX)
			return ((*value = (int) long_value) || 1);
		if (!ft_isspace(*str) || *str != '\0')
			return (-1);
	}
	return (0);
}

int		main()
{
	int		value;
	int		result;
	char 	*str;

	str = ft_strdup("1 2 3 4 5");
	result = parse_int_arg(&str, &value);
	ft_printf("res = %d, value = %d\n", result, value);
	result = parse_int_arg(&str, &value);
	ft_printf("res = %d, value = %d\n", result, value);
	while ((result = parse_int_arg(&str, &value)) > 0)
		ft_printf("res = %d, value = %d,  str = %s\n", result, value, str);
	if (result < 0)
		ft_printf("Error");
}