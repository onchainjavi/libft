/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:53:04 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:37:57 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (s[start + i] && len - i)
		i++;
	sub = malloc(sizeof(char) * (i + 1));
	if (sub == NULL)
		return (NULL);
	while (i--)
		sub[j++] = s[start++];
	sub[j] = '\0';
	return (sub);
}
