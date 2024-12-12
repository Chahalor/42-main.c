/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:33:14 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 12:33:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	sa(int *stack)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	sb(int *stack)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	ss(int *stack_a, int *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(int *stack_a, int *stack_b)
{
	int	i;

	i = stack_b[0];
	while (i > 0)
	{
		stack_a[i + 1] = stack_a[i];
		i--;
	}
	stack_a[1] = stack_b[1];
	stack_a[0]++;
	stack_b[0]--;
}

void	pb(int *stack_a, int *stack_b)
{
	int	i;

	i = stack_a[0];
	while (i > 0)
	{
		stack_b[i + 1] = stack_b[i];
		i--;
	}
	stack_b[1] = stack_a[1];
	stack_b[0]++;
	stack_a[0]--;
}
