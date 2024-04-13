/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:28:58 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:41 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (*(ptr + i))
	{
		if (*(ptr + i) == (char) c)
			return ((char *)ptr + i);
		i++;
	}
	if ((char) c == '\0')
		return ((char *)ptr + i);
	return (0);
}
/* int main()
{
	char* 
	ft_strchr(s, 't' + 256) == s)
}  */
