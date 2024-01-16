/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:37:55 by ahamdi            #+#    #+#             */
/*   Updated: 2024/01/16 13:33:36 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen( const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_read(int fd, char *str, int r_byt);
char	*ft_premierstr(char *str, int i);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t numel, size_t size_el);
char	*ft_desiemstr(char *s, size_t i);
char	*get_next_line(int fd);
#endif
