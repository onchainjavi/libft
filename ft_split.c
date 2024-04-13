/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:40:42 by jmarinel          #+#    #+#             */
/*   Updated: 2023/09/18 15:14:34 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **split, int i)
{
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free(split);
}

static int	ft_countw(const char *s, char c)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			ret++;
		i++;
	}
	return (ret);
}

static char	**ft_putwords(char const *s, int len, char **split, int i)
{
	int	j;

	j = 0;
	split[i] = malloc(sizeof(char) * (len + 1));
	if (!split[i])
	{
		ft_free(split, i);
		return (NULL);
	}
	while (len > 0)
	{
		split[i][j] = *s;
		j++;
		s++;
		len--;
	}
	split[i][j] = '\0';
	return (split);
}

static char	**ft_wordlen(char const *s, char c, char **split)
{
	int		len;
	int		i;

	i = 0;
	while (*s != '\0')
	{
		len = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (ft_putwords(s - len, len, split, i) == NULL)
				return (NULL);
		}
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**split;

	cnt = ft_countw(s, c);
	split = malloc(sizeof(char *) * (cnt + 1));
	if (split == NULL)
		return (NULL);
	if (ft_wordlen(s, c, split) == NULL)
		return (NULL);
	split[cnt] = 0;
	return (split);
}
/*int main() 
{
  const char s[] = Suspendisse";
  char c = ' ';
  char	**ret;
  int	i = 0;

  ret = ft_split("ggggggggggg", 'g');
  while (ret[i])
  {
	printf("%s\n",ret[i]);
	free(ret[i]);
	i++;
  }
  free (ret);
  return 0;
}*/
