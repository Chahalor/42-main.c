/** Big Header */

#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H

/* -----| Header |----- */
// Global
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

// Local
//...

/* -----| Macro |----- */

// ansii colors
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

// ansii formating
# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define BLINK "\033[5m"
# define REVERSE "\033[7m"

// formating
# define TITLE(title)			printf("\n" BOLD UNDERLINE title RESET "\n");
# define PART(part)				printf("\n" YELLOW BOLD part RESET "\n");
# define SUBPART(subpart)		printf("\n" YELLOW subpart RESET "\n");

# define REDIRECT(fd)			dup2(fd, STDOUT_FILENO);
# define RESTORE(_fd, _saved)	({dup2(_saved, _fd); close(_saved);})

# define PRINTF(format, ...) ({ \
	int _chars_written = printf(format, ##__VA_ARGS__); \
	fflush(stdout); \
	_chars_written; \
})

# define FT_PRINTF(format, ...) ({ \
	int _chars_written = ft_printf(format, ##__VA_ARGS__); \
	fflush(stdout); \
	_chars_written; \
})

# define TEST(test, _format, ...) ({ \
	t_test	*_new = (t_test *)malloc(sizeof(t_test) + sizeof(char) * (strlen(_format) + 1)); \
	if (!_new) \
		exiting(malloc_failed, "TEST: cannot malloc _new", NULL); \
	_new->result = -1; \
	_new->nb = g_nb_tests++; \
	_new->format = (char *)(_new + sizeof(test)); \
	_new->format = strcpy(_new->format, _format); \
	_new->printf_ret = (int)PRINTF(_format, ##__VA_ARGS__); \
	_new->printf_out = gnl(g_fd); \
	_new->ft_printf_ret = (int)FT_PRINTF(_format, ##__VA_ARGS__); \
	_new->ft_printf_out = gnl(g_fd); \
	test->next = _new; \
	_new->prev = test; \
})

/* -----| Enum |----- */

typedef enum e_error
{
	no_error = 0,
	invalid_argument,
	invalid_return,
	invalid_output,
	invalid_input,
	invalid_memory,
	invalid_file,
	malloc_failed,
	dup2_failed,
}	t_error;

/* -----| Struct |----- */

typedef struct s_test
{
	int		result;
	int		nb;
	int		printf_ret;
	int		ft_printf_ret;
	char	*format;
	char	*printf_out;
	char	*ft_printf_out;
	struct s_test	*next;
	struct s_test	*prev;
}	t_test;


typedef struct s_tester
{
	int		nb_test;
	t_test	*test;
}	t_tester;

/* -----| Function |----- */

char	*gnl(const int fd);

#endif // TEST_PRINTF_H