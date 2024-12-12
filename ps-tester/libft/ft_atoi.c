/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:23:42 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 13:45:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	is_space(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * @brief Convert a string to an integer
 * 
 * @param nptr The string to convert
 * @return The integer value of the string
 */
int	ft_atoi(const char *nptr)
{
	int				r;
	unsigned int	i;
	int				neg;

	neg = 1;
	r = 0;
	i = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	}
	return (r * neg);
}
