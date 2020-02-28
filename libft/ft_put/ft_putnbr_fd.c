/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:53:53 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/18 18:05:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == FT_INT_MIN)
		{
			ft_putstr_fd(FT_INT_MIN_STR, fd);
			return ;
		}
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n < 10)
	{
		ft_putchar_fd((char)(n + '0'), fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
}
