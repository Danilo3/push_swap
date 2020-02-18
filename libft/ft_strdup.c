/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 03:00:59 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/28 18:13:31 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		size;

	if (!src)
		return (FT_NULL);
	size = ft_strlen(src);
	dup = (char*)malloc((1 + size) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
