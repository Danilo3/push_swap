/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:49:05 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/16 15:51:26 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*ft_lstdup(t_list *src)
{
	t_list	*new_lst;
	void	*new_content;

	new_content = malloc(src->content_size);
	ft_memmove(new_content, src->content, src->content_size);
	if (!new_content)
		return (NULL);
	new_lst = ft_lstnew(new_content, src->content_size);
	if (!new_lst)
		return (NULL);
	return (new_lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *pl;
	t_list **new_lst;
	size_t len;
	size_t i;

	i = 0;
	if (!lst)
		return (NULL);
	len = ft_lstlen(lst);
	new_lst = (t_list**)malloc(sizeof(t_list*) * len);
	pl = lst;
	while (pl)
	{
		new_lst[i] = ft_lstdup(f(pl));
		if (i != 0)
			(new_lst[i - 1])->next = new_lst[i];
		pl = pl->next;
		i++;
	}
	(new_lst[0])->next = new_lst[1];
	return (new_lst[0]);
}
