/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:51:32 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/18 18:05:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Accepts pointer to value, pointer to is_neg var and str
 ** return (1) if (*value) == INT_MIN or (*value) = 0
*/

static int	ft_is_border(int *value, int *is_neg, char *str)
{
	if (*value == 0)
	{
		ft_strcpy(str, "0");
		return (1);
	}
	if (*value < 0)
	{
		*is_neg = 1;
		if (*value == FT_INT_MIN)
		{
			ft_strcpy(str, FT_INT_MIN_STR);
			return (1);
		}
		*value = -(*value);
	}
	return (0);
}

/*
 **  Accepts an integer value and a pointer to a string.
 **  Converts an integer to a string.
*/

void		ft_itostr(int value, char *str)
{
	int		is_neg;
	size_t	i;

	i = 0;
	is_neg = 0;
	if (ft_is_border(&value, &is_neg, str))
		return ;
	while (value)
	{
		str[i++] = (char)((value % 10) + '0');
		value /= 10;
	}
	if (is_neg)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
}
