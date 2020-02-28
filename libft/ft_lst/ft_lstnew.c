/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:02:37 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/18 18:05:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *fresh;

	fresh = (t_list*)malloc(sizeof(t_list));
	if (!fresh)
		return (NULL);
	fresh->next = NULL;
	if (!content)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		fresh->content = malloc(content_size);
		if (!fresh->content)
			return (NULL);
		ft_memmove(fresh->content, content, content_size);
		fresh->content_size = content_size;
	}
	return (fresh);
}
