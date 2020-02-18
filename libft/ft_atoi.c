/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:13:14 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/18 18:05:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** TODO: understand overflow ... and dot it shorter
*/

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

int			ft_atoi(const char *str)
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
	return ((int)(res * is_neg));
}
