/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test-printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:33:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/31 10:48:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Big Header */

#include "test-printf.h"
#include "../ft_printf.h"

int	g_nb_tests = 0;
int	g_saved_stdout = -1;
int	g_fd = -1;

__attribute__((noreturn)) void	exiting(const int code, const char *err, void *ptr)
{
	if (ptr)
		free(ptr);
	if (err)
		perror(err);
	exit(code);
}

__attribute__((malloc)) char	*gnl(const int fd)
{
	char	*line = NULL;
	char	*tmp = NULL;
	char	buf[2] = {0};
	int		ret = 0;

	line = (char *)malloc(sizeof(char) * 2);
	while (line && (ret = read(fd, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
			break;
		tmp = line;
		line = (char *)realloc(line, sizeof(char) * (strlen(line) + 2));
		if (!line)
			exiting(malloc_failed, "GNL: cannot realloc line", tmp);
		line = strcat(line, buf);
	}
	if (ret < 0)
		exiting(invalid_input, "GNL: read failed", line);
	return (line);
}

void	args_handler(int argc, char *argv[])
{
	if (argc > 1)
	{
		printf("Usage: %s\n", argv[0]);
		exit(1);
	}
}
# define TEST(test, _format, ...) ({ \
	t_test	*_new = (t_test *)malloc(sizeof(t_test) + sizeof(char) * (strlen(_format) + 1)); \
	if (!_new) \
		exiting(malloc_failed, "TEST: cannot malloc _new", NULL); \
	_new->result = -1; \
	_new->nb = g_nb_tests++; \
	_new->format = (char *)(_new + sizeof(test)); \
	_new->format = strcpy(_new->format, _format); \
	_new->printf_ret = PRINTF(_format, ##__VA_ARGS__); \
	_new->printf_out = gnl(g_fd); \
	_new->ft_printf_ret = FT_PRINTF(_format, ##__VA_ARGS__); \
	_new->ft_printf_out = gnl(g_fd); \
	test->next = _new; \
	})

int	tester(void)
{
	return (0);
}

/** @todo */
int main(int argc, char *argv[])
{
	args_handler(argc, argv);

	g_saved_stdout = dup(STDOUT_FILENO);
	g_fd = open(".temp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (g_fd < 0)
		exiting(dup2_failed, "main: cannot dup stdout", NULL);
	t_test	*test = malloc(sizeof(t_test));
	if (!test)
		exiting(malloc_failed, "main: cannot malloc test", NULL);
	test->next = NULL;
	REDIRECT(g_fd);
	TEST(test, "Hello, World!\n");
	// RESTORE(g_fd);
	dup2(g_saved_stdout, STDOUT_FILENO);
	close(g_saved_stdout);

	printf("Test %d: %s\n", test->nb, test->printf_out);
	free(test->printf_out);
	close(g_fd);
	free(test);
	return (0);
}
