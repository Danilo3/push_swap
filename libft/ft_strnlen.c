/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:16:49 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/16 17:06:32 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t i;

	i = 0;
	while (s[i] && i <= maxlen)
		i++;
	return (ft_min(i, maxlen));
}
