/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:50:36 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:16 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cpy;
	unsigned int	i;

	i = 0;
	cpy = ft_strdup((s));
	if (cpy == NULL)
		return (NULL);
	while (cpy[i])
	{
		cpy[i] = f(i, cpy[i]);
		i++;
	}
	return (cpy);
}
