/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:35:00 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/19 15:05:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file get_next_line_utils.c
 * @brief Get the length of a string
 * 
 * @param s The string
 * @return The length of the string
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

/**
 * @file get_next_line_utils.c
 * @brief Locate a character in a string
 * 
 * @param s The string
 * @param c The character to locate
 * @return A pointer to the located character or NULL 
 * 			if the character does not appear in the string
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		if (s[i++] == (unsigned char)c)
			return (&((char *)s)[i - 1]);
	if (s[i++] == (unsigned char)c)
		return (&((char *)s)[i - 1]);
	return (NULL);
}

/**
 * @file get_next_line_utils.c
 * @brief Join two strings
 * 
 * @param s1 The first string
 * @param s2 The second string
 * @return The new string or NULL if an error occurs
 */
char	*str_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	free(s1);
	return (result);
}
