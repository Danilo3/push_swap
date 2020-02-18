/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:16:19 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/14 01:02:09 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	t_uchar	*ps;

	i = 0;
	ps = (t_uchar*)s;
	while (i < n)
	{
		if (ps[i] == (t_uchar)c)
			break ;
		i++;
	}
	if (i == n)
		return (FT_NULL);
	else
		return (ps + i);
}
