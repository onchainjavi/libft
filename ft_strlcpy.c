/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:52:43 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/24 20:40:23 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (dstsize < 1)
		return (len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*int main ()
{
	char src[5] = "birra";
	char dst[5];
	size_t size = 5;
	unsigned int ret;
	unsigned int r_ret;

	ret = ft_strlcpy(dst, src, size);
	r_ret = strlcpy(dst, src, size);
	printf("%u\n", ret);
	printf("the real return is %u\n", r_ret);
	return(0);
}*/
