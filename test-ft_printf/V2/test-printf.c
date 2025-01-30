/** Big Header */

#include "test-printf.h"
#include "../ft_printf.h"

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

void	new_test(t_test *test, const char *format)
{
	test->format = strdup(format);	// @todo: make strdup()
	test->printf_out = NULL;
	test->printf_ret = 0;
	test->ft_printf_ret = 0;
	test->nb = test->prev->nb + 1;
	test->next = (t_test *)malloc(sizeof(t_test));
	if (!test->next)
		exiting(malloc_failed, "new_test: cannot malloc test->next", test);
	test->next->prev = test;
	test = test->next;
}

void	free_test(t_test *test)
{
	t_test	*tmp = NULL;

	while (test)
	{
		tmp = test;
		test = test->next;
		if (tmp->format)
			free(tmp->format);
		if (tmp->printf_out)
			free(tmp->printf_out);
		if (tmp->ft_printf_out)
			free(tmp->ft_printf_out);
		free(tmp);
	}
}

void	do_test(t_test *test, int fd)
{
	test->printf_ret = printf(test->format);
	test->printf_out = gnl(fd);
	test->ft_printf_ret = ft_printf(test->format);
	test->ft_printf_out = gnl(fd);
	test->result = (test->printf_ret == test->ft_printf_ret
		&& !strcmp(test->printf_out, test->ft_printf_out));
}

int	tester(void)
{
	t_tester	*tester = NULL;
	t_test		*test = NULL;

	tester = (t_tester *)malloc(sizeof(t_tester));
	if (!tester)
		exiting(malloc_failed, "tester: cannot malloc tester", NULL);
	tester->nb_test = 0;
	tester->test = (t_test *)malloc(sizeof(t_test));
	if (!tester->test)
		exiting(malloc_failed, "tester: cannot malloc tester->test", tester);
	test = tester->test;
	return (0);
}

/** @todo */
int main(int argc, char *argv[])
{
	args_handler(argc, argv);
	tester();
	return (0);
}
