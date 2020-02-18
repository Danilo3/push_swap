/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartswith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 04:43:34 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/18 18:05:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_startswith(const char *str, const char *start)
{
	size_t i;

	i = 0;
	while (str[i] && start[i])
	{
		if (str[i] != start[i])
			return (FT_FALSE);
		i++;
	}
	if (start[i])
		return (FT_FALSE);
	return (FT_TRUE);
}
