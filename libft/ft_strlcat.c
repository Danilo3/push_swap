/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 02:55:16 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/16 17:09:30 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t n;
	size_t dlen;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	n = size + 1;
	while (--n != 0 && dst[i] != '\0')
		i++;
	dlen = i;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (src[j] != '\0')
	{
		if (n != 1)
		{
			dst[i++] = src[j];
			n--;
		}
		j++;
	}
	dst[i] = '\0';
	return (dlen + j);
}
