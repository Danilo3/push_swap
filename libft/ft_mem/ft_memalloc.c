/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 03:27:49 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/18 18:05:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
