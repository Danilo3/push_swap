/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:13:59 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/11 16:28:23 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_ch_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char		*ft_strrev(char *str)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(str);
	if (j != 0)
		j--;
	while (i < j)
	{
		ft_ch_swap(str + i, str + j);
		j--;
		i++;
	}
	return (str);
}
