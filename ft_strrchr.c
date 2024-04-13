/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:38:23 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:05 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
	{
		while ((char)*s != '\0')
			s++;
		return ((char *)s);
	}
	else
	{
		while ((char)*s != '\0')
		{
			s++;
			i++;
		}
		while (i >= 0)
		{
			if ((char)*s == ((char)c))
				return ((char *)s);
			s--;
			i--;
		}
	}
	return (0);
}
