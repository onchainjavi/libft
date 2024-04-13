/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:09:21 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:31 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*buf;

	len = ft_strlen(s1) + ft_strlen(s2);
	buf = malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	while (*s1)
		*buf++ = *s1++;
	while (*s2)
		*buf++ = *s2++;
	*buf = '\0';
	return (buf - len);
}
