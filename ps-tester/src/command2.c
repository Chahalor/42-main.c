/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:33:58 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 12:34:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	ra(int *stack)
{
	int	tmp;
	int	i;

	tmp = stack[0];
	i = 1;
	while (i < stack[0])
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[tmp] = stack[1];
}

void	rb(int *stack)
{
	int	tmp;
	int	i;

	tmp = stack[0];
	i = 1;
	while (i < stack[0])
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[tmp] = stack[1];
}

void	rr(int *stack_a, int *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(int *stack)
{
	int	tmp;
	int	i;

	tmp = stack[1];
	i = stack[0];
	while (i > 1)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[1] = stack[tmp];
}

void	rrb(int *stack)
{
	int	tmp;
	int	i;

	tmp = stack[1];
	i = stack[0];
	while (i > 1)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[1] = stack[tmp];
}
