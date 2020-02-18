/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:29:40 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/28 18:30:59 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubf(char **ps, size_t start, size_t len)
{
	char	*tmp;

	tmp = ft_strsub(*ps, start, len);
	ft_strdel(ps);
	return (tmp);
}
