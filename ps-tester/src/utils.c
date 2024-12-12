/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:27:32 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 14:57:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

// char	**ft_realloc(char **ptr, size_t size)
// {
// 	char	**new;
// 	size_t	i;

// 	new = (char **)ft_calloc(size + 1, sizeof(char *));
// 	if (!new)
// 		return (NULL);
// 	i = 0;
// 	while (ptr[i])
// 	{
// 		new[i] = ptr[i];
// 		if (i > 0)
// 			free(ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// 	new[i] = NULL;
// 	return (new);
// }

char	**ft_realloc(char **ptr, size_t size)
{
	char	**new;
	size_t	i;

	new = (char **)malloc((size + 1) * sizeof(char *) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		new[i] = ptr[i];
		if (i > 0)
			free(ptr[i]);
		i++;
	}
	free(ptr);
	new[i] = NULL;
	return (new);
}
