/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:52:09 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/16 15:52:09 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		size;
	char	*number;

	size = ft_count_digits(n);
	if (n < 0)
		size++;
	number = ft_strnew(size);
	if (!number)
		return (FT_NULL);
	ft_itostr(n, number);
	return (number);
}
