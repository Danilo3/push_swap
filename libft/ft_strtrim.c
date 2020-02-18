/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:03:48 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/16 16:24:48 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_iswhitespace(char ch)
{
	return (ch == '\t' || ch == '\n' || ch == ' ');
}

char		*ft_strtrim(char const *s)
{
	char	*trimmed_str;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	j = len - 1;
	while (s[i] && ft_iswhitespace(s[i]))
		i++;
	if (i == len)
		return (ft_strnew(1));
	while (j != 0 && ft_iswhitespace(s[j]))
		j--;
	len -= (len - j - 1) + i;
	trimmed_str = (char*)malloc(sizeof(char) * len + 1);
	if (!trimmed_str)
		return (NULL);
	ft_strncpy(trimmed_str, s + i, len);
	trimmed_str[len] = '\0';
	return (trimmed_str);
}
