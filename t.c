# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#define BUFFER_SIZE 10000000
# endif
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
	// free(s);
	// s = NULL;
	return (res);
}

char *ft_desiemstr(char *s)
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
	s = NULL;
	return(r);
}
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
//    free(str);
//    str =tem;
    return (line);
}
int main()
{
    int fd = open("read_error.txt",O_RDWR);
    char *line ;
    line = get_next_line(fd);
    printf("%s",line);
	line = get_next_line(fd);
    printf("%s",line);
	line = get_next_line(fd);
    printf("%s",line);
	line = get_next_line(fd);
    printf("%s",line);
	line = get_next_line(fd);
    printf("%s",line);
   
}