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

	// fflush(stdout);
	// lseek(fd, 0, SEEK_SET);
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

int	tester(void)
{
	int		temp_fd = -1;
	int		stdout_fd = -1;
	char	*printf_output = NULL;
	char	*ft_printf_output = NULL;

	temp_fd = open(".temp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (temp_fd < 0)
		return (perror("opening temp file failed"), 1);

	stdout_fd = dup(STDOUT_FILENO);
	if (stdout_fd < 0)
		return (perror("dupping STDOUT failed"), 1);

	if (dup2(temp_fd, STDOUT_FILENO) < 0)
		return (perror("redirecting STDOUT failed"), 1);

	printf("Hello, World!\n");
	READ_FD(temp_fd, printf_output);
	ft_printf("Hello, World!\n");
	READ_FD(temp_fd, ft_printf_output);

	if (dup2(stdout_fd, STDOUT_FILENO) < 0)
		return (perror("restoring STDOUT failed"), 1);

	printf("printf: %s\n", printf_output);
	printf("ft_printf: %s\n", ft_printf_output);
	free(printf_output);
	close(temp_fd);
	close(stdout_fd);

	return (0);
}

/** @todo */
int main(int argc, char *argv[])
{
	args_handler(argc, argv);
	tester();
	return (0);
}
