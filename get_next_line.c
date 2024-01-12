/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:37:45 by ahamdi            #+#    #+#             */
/*   Updated: 2024/01/12 11:41:19 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		r_byt;
	buff = malloc((BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	r_byt = 1;
	while (!ft_strchr(str, '\n') && r_byt != 0)
	{
		r_byt = read(fd, buff, BUFFER_SIZE);
		if (r_byt == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[r_byt] = '\0';
		str = ft_strjoin(str, buff);
	}
    free(buff);
	return (str);
}
char *get_next_line(int fd) {
    static char *str;
    char *line;
	// char *tem = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0) 
        return (NULL);
    str = ft_read(fd, str);
    if (!str)
    {
        return NULL;
    }
    line = ft_premierstr(str);
    str = ft_desiemstr(str);
    return (line);
}