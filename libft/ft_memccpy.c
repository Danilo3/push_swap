/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:23:50 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/14 00:35:07 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	t_uchar	*pd;
	t_uchar	*ps;

	i = 0;
	pd = (t_uchar *)dst;
	ps = (t_uchar *)src;
	while (i < n)
	{
		pd[i] = ps[i];
		if (ps[i] == (t_uchar)c)
			return (pd + i + 1);
		i++;
	}
	return (NULL);
}
