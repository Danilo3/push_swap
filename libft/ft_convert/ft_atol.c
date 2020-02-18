//
// Created by Aletha Yellin on 18/02/2020.
//

#include "libft.h"

static int	is_llong_max_overflow(unsigned long n, char c, int sign)
{
	return ((n > FT_NEAR_LLONG_MAX || \
			(n == FT_NEAR_LLONG_MAX && c > 7)) && sign == 1);
}

static int	is_llong_min_overflow(unsigned long n, char c, int sign)
{
	return ((n > FT_NEAR_LLONG_MAX || \
			(n == FT_NEAR_LLONG_MAX && c > 8)) && sign == -1);
}

long		ft_atol(const char *str)
{
	unsigned long	res;
	int				is_neg;

	is_neg = 1;
	res = 0ul;
	while (*str && ft_isspace(*str))
		++str;
	if (*str == '-')
		is_neg = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && ft_isdigit(*str))
	{
		if (is_llong_max_overflow(res, (char)((*str) - '0'), is_neg))
			return (-1);
		else if (is_llong_min_overflow(res, (char)((*str) - '0'), is_neg))
			return (0);
		res = res * 10 + (*str - '0');
		++str;
	}
	return ((long)(res * is_neg));
}