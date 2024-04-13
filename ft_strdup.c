/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:10:59 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:39 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;

	len = ft_strlen(s1);
	dup = malloc((sizeof(char) * (len + 1)));
	if (dup == NULL)
		return (NULL);
	while (*s1)
		*dup++ = *s1++;
	*dup = '\0';
	return (dup - len);
}
