/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:22:27 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 13:47:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each
 * and returns a pointer to the allocated memory.
 * 
 * @param nmemb Number of elements.
 * @param size Size of each element.
 * @return void* Pointer to the allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}
