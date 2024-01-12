/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:26:19 by ahamdi            #+#    #+#             */
/*   Updated: 2024/01/12 12:24:24 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen( const char *str)
{
	size_t	i;

	if(!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	int		size_total;
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if(!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	size_total = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(size_total + 1);
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
    if(!s)
        return(NULL);
	i = 0;
	while (s[i] != '\0' || (char)c == '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}


char *ft_premierstr(char *s) 
  {
	int		i;
	char	*res;
	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	res = malloc((i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
char	*ft_desiemstr(char *s)
{
	size_t i;
	size_t j;
	char *r;

	i = 0;
	j = 0;
    if(!s)
        return(NULL);
	while(s[i] && s[i] != '\n')
		i++;
	if(s[i] == '\0')
	{
		free(s);
		return(NULL);
	}
	r = malloc((ft_strlen(s) - i) + 1);
	if(!r)
	    return(NULL);
	i++;
	while(s[i])
		r[j++] = s[i++];
	r[j] = '\0';
     free(s);
	return(r);
}