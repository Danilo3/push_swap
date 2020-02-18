/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:37:54 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/16 14:13:19 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar_utf8_fd(char c, int fd)
{
	unsigned char c1;
	unsigned char c2;
	unsigned char mask;

	mask = (unsigned char)192;
	if (c >= 0)
		write(fd, &c, 1);
	else
	{
		c1 = mask | ((unsigned char)c >> 6u);
		c2 = (FT_CHAR_MAX) | (((unsigned char)c << 2u) >> 2u);
		write(fd, &c1, 1);
		write(fd, &c2, 1);
	}
}
