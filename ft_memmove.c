/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:44 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:39:05 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = (unsigned char *)dst;
	ptrs = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (ptrs < ptrd)
		while (++i <= len)
			ptrd[len - i] = ptrs[len - i];
	else
		while (len-- > 0)
			*(ptrd++) = *(ptrs++);
	return (dst);
}
/*
#include <stdio.h>

int main()
{
	unsigned char src[6] = "hello!";
	ft_memmove(src, src + 3, 3);
	printf("%s\n", src);
	return (0);
}*/
