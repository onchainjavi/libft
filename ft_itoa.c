/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:34:35 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/24 20:21:31 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(unsigned int n, int neg)
{
	int	i;

	i = 0;
	if (neg < 0 || n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	char	*ft_putnbr( unsigned int n, char *str, int len)
{
	if (n / 10)
	{
		ft_putnbr(n / 10, str, len - 1);
	}
	str[len - 1] = (n % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				neg;
	int				len;
	unsigned int	nbr;

	neg = 0;
	if (n < 0)
	{
		neg = -1;
		nbr = (unsigned int) -n;
	}
	else
		nbr = (unsigned int) n;
	len = nbr_len(nbr, neg);
	str = malloc (sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (neg < 0)
	{
		str[0] = '-';
	}
	str[len] = '\0';
	return (ft_putnbr(nbr, str, len));
}
