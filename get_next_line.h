/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:37:55 by ahamdi            #+#    #+#             */
/*   Updated: 2024/01/11 22:48:05 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
#include<string.h>
# ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
# endif
char *get_next_line(int fd);
size_t	ft_strlen( const char *str);
char	*ft_strchr(const char *s, int c);
char    *ft_strjoin(char  *s1, char  *s2);
char *ft_premierstr(char *s);
char *ft_desiemstr(char *s);
#endif
