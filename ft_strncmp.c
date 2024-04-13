/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:45:41 by jmarinel          #+#    #+#             */
/*   Updated: 2023/07/24 13:11:14 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if ((!(unsigned char)*s1) && (!(unsigned char)*s2))
			return (0);
		else if ((!(unsigned char)*s1))
			return (-1);
		else if ((!(unsigned char)*s2))
			return (1);
		else if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else
		{
			s1++;
			s2++;
			n--;
		}
	}
	return (0);
}
