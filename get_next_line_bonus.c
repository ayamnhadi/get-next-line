/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:34:52 by ahamdi            #+#    #+#             */
/*   Updated: 2024/01/16 15:48:11 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	size_t	len ;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	dup = malloc ((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_calloc(size_t numel, size_t size_el)
{
	size_t	size_totat ;
	void	*ma;
	size_t	i;

	i = 0;
	size_totat = numel * size_el;
	ma = malloc(size_totat);
	if (ma == NULL)
		return (NULL);
	while (i < numel)
	{
		((unsigned char *)ma)[i] = 0;
		i++;
	}
	return (ma);
}

void	ft_chekfree(char *str, char *buff)
{
	free(buff);
	free(str);
}

char	*ft_read(int fd, char *str, int r_byt)
{
	char	*buff;
	char	*temp;

	buff = malloc((BUFFER_SIZE + 1));
	if (!buff)
	{
		free(str);
		return (NULL);
	}
	while (r_byt != 0 && !ft_strchr(str, '\n'))
	{
		r_byt = read(fd, buff, BUFFER_SIZE);
		if (r_byt == -1)
		{
			ft_chekfree(str, buff);
			return (NULL);
		}
		buff[r_byt] = '\0';
		temp = str;
		str = ft_strjoin(str, buff);
		free(temp);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;
	size_t		i;
	int			r_byt;

	r_byt = 1;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0) 
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = ft_read(fd, str[fd], r_byt);
	if (!str[fd])
		return (NULL);
	line = ft_premierstr(str[fd], i);
	if (!line)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = ft_desiemstr(str[fd], i);
	return (line);
}
