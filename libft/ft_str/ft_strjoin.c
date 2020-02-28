/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:14:48 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/18 18:05:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;

	if (!s1 || !s2)
		return (FT_NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s2_len + s1_len;
	if (len < s1_len || len < s2_len)
		return (NULL);
	new = ft_strnew(len + 1);
	if (!new)
		return (FT_NULL);
	ft_strncpy(new, s1, s1_len);
	ft_strncat(new, s2, s2_len);
	return (new);
}
