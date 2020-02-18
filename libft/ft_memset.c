/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:25:36 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/17 19:25:36 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	t_uchar	*ptr;
	size_t	i;

	i = 0;
	ptr = (t_uchar*)s;
	while (i < n)
		ptr[i++] = (t_uchar)c;
	return (ptr);
}
