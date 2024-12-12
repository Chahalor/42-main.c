/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:30:44 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 13:30:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

/**
 * @brief Compares the two strings s1 and s2, but at most n bytes.
 * 
 * @param s1 First string to be compared.
 * @param s2 Second string to be compared.
 * @param n Number of bytes to be compared.
 * @return int 0 if the two strings are identical, otherwise the difference
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	if (s1[0] == '\0')
		return (-(unsigned char)s2[0]);
	else if (s2[0] == '\0')
		return ((unsigned char)s1[0]);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i] || s1[i] == '\0')
			return (-(unsigned char)s2[i]);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i] || s2[i] == '\0')
			return ((unsigned char)s1[i]);
		i++;
	}
	return (0);
}
