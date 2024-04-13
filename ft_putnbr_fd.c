/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:40:56 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:46 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				sign;
	char			c;

	if (fd != 1)
		return (-1);
	sign = 1;
	if (n < 0)
	{
		nb = (unsigned int) -n;
		sign *= -1;
		ft_putchar_fd('-', fd);
	}
	else
		nb = (unsigned int) n;
	if (nb / 10)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	c = nb % 10 + '0';
	ft_putchar_fd(c, fd);
	return (0);
}
