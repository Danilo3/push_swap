/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:28:08 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/18 18:05:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinf(char *s1, char *s2, int flag)
{
	char	*tmp;

	if (s1)
		tmp = ft_strjoin(s1, s2);
	else
		tmp = ft_strdup(s2);
	if (flag == 1 || flag == 3)
		ft_strdel(&s1);
	if (flag == 2 || flag == 3)
		ft_strdel(&s2);
	return (tmp);
}
