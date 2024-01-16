/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:35:27 by ahamdi            #+#    #+#             */
/*   Updated: 2024/01/16 15:46:38 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
