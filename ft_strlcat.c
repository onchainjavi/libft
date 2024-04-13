/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:43:22 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:27 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_d;
	size_t	len_s;

	len_d = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	i = len_d;
	j = i;
	while (src[i - j] && i + 1 < dstsize)
	{
		dst[i] = src[i - j];
		i++;
	}
	dst[i] = '\0';
	if (dstsize < len_d)
	{
		return (len_s + dstsize);
	}
	else
		return (len_d + len_s);
}
/*
int main(int argc, char** argv)
{
	const char src[5] = "hola";
	char dst[8] = "adeiii";
	size_t size = 6;
	size_t ret;
	size_t r_ret;

	ret = 0;
	r_ret = 0;
	if (argv[1][0] == 'o' && argc != 0)
	{
		ret = ft_strlcat(dst, src, size);
		printf("the concatenated string is %s\n", dst);
		printf("the return is %zu\n", ret);
	}
	else if (argv[1][0] == 'r')
	{
		r_ret = strlcat(dst, src, size);
		printf("the real return is %zu\n", r_ret);
		printf("the real concatenated string is %s\n", dst);
	}
	return(0);
}*/
