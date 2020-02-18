/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:45:34 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/14 20:45:34 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *pl;

	pl = FT_NULL;
	if (!lst)
		return ;
	pl = lst;
	while (pl)
	{
		f(pl);
		pl = pl->next;
	}
}
