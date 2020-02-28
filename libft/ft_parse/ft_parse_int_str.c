/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 03:23:46 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/28 03:23:49 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 **  parse str of ints, separated by spaces
 **  returns 1 if was value, 0 if arg empty, -1 if error
*/

int		ft_parse_int_str(char **arg, int *next)
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
		if (!ft_isspace(*str) && *str != '\0')
			return (-1);
		if (long_value >= INT_MIN && long_value <= INT_MAX)
			return ((*next = (int)long_value) || 1);
	}
	if (!ft_isspace(*str))
		return (-1);
	return (0);
}
