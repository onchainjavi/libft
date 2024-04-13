/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:56:11 by jmarinel          #+#    #+#             */
/*   Updated: 2023/08/30 18:13:07 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_free_gnl(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
		str = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*ft_fill(char *storage, int fd)
{
	char		*buf;
	int			bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free_gnl(&storage));
	bytes = 1;
	while (bytes > 0 && !ft_strutil(storage, 2))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			ft_free_gnl(&buf);
			return (ft_free_gnl(&storage));
		}
		if (bytes > 0)
		{
			buf[bytes] = '\0';
			storage = ft_strjoin_gnl(storage, buf);
			if (!storage)
				return (ft_free_gnl(&buf));
		}
	}
	free (buf);
	return (storage);
}

char	*ft_get_line(char *storage)
{
	char		*line;
	ssize_t		i;

	i = ft_strutil(storage, 3);
	if (storage[i] == '\n')
		line = ft_substr_gnl(storage, 0, i + 1);
	else
		line = ft_substr_gnl(storage, 0, i);
	return (line);
}

char	*ft_clean(char *s, char *line)
{
	char	*scopy;

	if (ft_strutil(s, 2) && s[ft_strutil(s, 3) + 1])
	{
		scopy = s;
		s = ft_substr_gnl(s, ft_strutil(line, 1), ft_strutil(s, 1));
		if (scopy != NULL)
			free(scopy);
		if (s == NULL)
			return (ft_free_gnl(&s));
	}
	else
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = ft_fill(storage[fd], fd);
	if (!storage[fd])
		return (NULL);
	line = ft_get_line(storage[fd]);
	if (line == NULL)
		return (ft_free_gnl(&storage[fd]));
	storage[fd] = ft_clean(storage[fd], line);
	return (line);
}
