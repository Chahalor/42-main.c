/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:04:35 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 15:03:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	*read_stack(int argc, char *argv[])
{
	int	*stack;
	int	i;

	stack = malloc(sizeof(int) * (argc - 1));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		stack[i] = ft_atoi(argv[i + 1]);
		if (stack[i] == 0 && ft_strncmp(argv[i + 1], "0", argc - 1))
		{
			free(stack);
			exit(NON_NUMERIC_VALUE);
		}
		i++;
	}
	return (stack);
}

char	**read_commands(void)
{
	char	**commands;
	char	*line;
	int		i;

	commands = ft_calloc(2, sizeof (char *));
	commands[0] = NULL;
	if (!commands)
		return (NULL);
	line = get_next_line(0);
	i = 0;
	while (line)
	{
		commands[i] = line;
		commands = ft_realloc(commands, sizeof (char *) * (i + 1));
		if (!commands)
			return (NULL);
		i++;
		line = get_next_line(0);
	}
	return (commands);
}

void	test(int *stack_a, int *stack_b, char **commands)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		if (!ft_strncmp(commands[i], SA, 3))
			sa(stack_a);
		else if (!ft_strncmp(commands[i], SB, 3))
			sb(stack_b);
		else if (!ft_strncmp(commands[i], SS, 3))
			ss(stack_a, stack_b);
		else if (!ft_strncmp(commands[i], PA, 3))
			pa(stack_a, stack_b);
		else if (!ft_strncmp(commands[i], PB, 3))
			pb(stack_a, stack_b);
		else if (!ft_strncmp(commands[i], RA, 3))
			ra(stack_a);
		else if (!ft_strncmp(commands[i], RB, 3))
			rb(stack_b);
		else if (!ft_strncmp(commands[i], RR, 3))
			rr(stack_a, stack_b);
		else if (!ft_strncmp(commands[i], RRA, 4))
			rra(stack_a);
		else if (!ft_strncmp(commands[i], RRB, 4))
			rrb(stack_b);
		else if (!ft_strncmp(commands[i], RRR, 4))
			rrr(stack_a, stack_b);
		else
		{
			write(2, "Error\n", 6);
			free(stack_a);
			free(stack_b);
			exit(ERROR);
		}
		i++;
	}
}

int	is_sorted(int *stack)
{
	int	i;

	i = 0;
	while (i < stack[0] - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		*stack_a;
	int		*stack_b;
	char	**commands;

	stack_a = read_stack(argc, argv);
	stack_b = ft_calloc(argc - 1, sizeof(int));
	commands = read_commands();
	if (!stack_a || !stack_b || !commands)
	{
		write(2, "Error\n", 6);
		return (free(stack_a), free(stack_b), free(commands), MALLOC_ERROR);
	}
	test(stack_a, stack_b, commands);
	if (is_sorted(stack_a) && !stack_b[0])
	{
		write(1, "OK\n", 3);
		return (free(stack_a), free(stack_b), free(commands), OK);
	}
	write(1, "KO\n", 3);
	return (free(stack_a), free(stack_b), free(commands), KO);
}
