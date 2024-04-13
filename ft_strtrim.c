/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:25:46 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:00 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*trim;

	len = ft_strlen(s1);
	i = 0;
	j = 0;
	while (ft_check(s1[i], set) == 1)
		i++;
	if (len <= i)
		return (ft_strdup(""));
	while (ft_check(s1[len - 1], set) == 1)
		len--;
	trim = malloc(sizeof(char) * (len - i + 1));
	if (!trim)
		return (NULL);
	while (len - i)
		trim[j++] = s1[i++];
	trim[j] = '\0';
	return (trim);
}
/*
#include <stdio.h>
int main(void)
{
	const char s1[] = "lorem ipsum dolor sit amet";
	
	printf("return is: %s",ft_strtrim(s1, "te"));
}*/