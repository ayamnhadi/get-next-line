/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:35:57 by ahamdi            #+#    #+#             */
/*   Updated: 2024/01/16 15:45:36 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size_total;
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	size_total = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(size_total + 1);
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0' || (char)c == '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_premierstr(char *s, int i)
{
	char	*res;
	int		len;

	len = 0;
	if (!s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		i++;
		len++;
	}
	if (s[i] == '\n')
		len++; 
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*ft_desiemstr(char *s, size_t i)
{
	char	*r;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	r = malloc((ft_strlen(s) - i) + 1);
	if (!r)
	{
		free(s);
		return (NULL);
	}
	i++;
	while (s[i])
		r[j++] = s[i++];
	r[j] = '\0';
	free(s);
	return (r);
}
