/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:35:25 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/19 15:05:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*str_join(char *s1, char *s2);

char	*get_next_line(int fd);

#endif