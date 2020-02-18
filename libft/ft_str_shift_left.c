/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_shift_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:38:08 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/23 15:41:27 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_shift_left(char *str, size_t from)
{
	size_t new_size;

	new_size = ft_strlen(str + from);
	ft_memmove(str, str + from, new_size);
	str[new_size] = '\0';
}
