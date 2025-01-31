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
# define RESTORE(fd)			dup2(g_saved_stdout, fd);

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