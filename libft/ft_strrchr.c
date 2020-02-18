/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 03:38:39 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/16 16:19:31 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s);
	while (len != 0)
	{
		if (s[len] == (char)c)
			return ((char*)(s + len));
		len--;
	}
	if (s[0] == (char)c)
		return ((char*)(s));
	return (FT_NULL);
}
