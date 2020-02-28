/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:44:54 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/18 18:05:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t len)
{
	t_uchar			*pd;
	const t_uchar	*ps;
	size_t			i;

	pd = (t_uchar*)dst;
	ps = (const t_uchar*)src;
	if (!dst && !src)
		return (FT_NULL);
	i = len;
	while (i > 0)
	{
		i--;
		pd[i] = ps[i];
	}
	return (dst);
}
