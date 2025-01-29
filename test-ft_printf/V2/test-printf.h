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
# define TITLE(title)		printf("\n" BOLD UNDERLINE title RESET "\n");
# define PART(part)			printf("\n" YELLOW BOLD part RESET "\n");
# define SUBPART(subpart)	printf("\n" YELLOW subpart RESET "\n");

#define READ_FD(fd, output) ({ \
	fflush(stdout); \
	lseek(fd, 0, SEEK_SET); \
	output = gnl(fd); \
})
// tester
# define TESTER_STDIN(user, expected)	((user) == (expected) ? 1 : 0)
# define TESTER_OUTPUT(user, expected)	((user) == (expected) ? 1 : 0)
# define TESTER(in, out)				((in) && (out) ? printf(GREEN "OK " RESET) : printf(RED "KO " RESET))

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
}	t_error;

/* -----| Struct |----- */


/* -----| Function |----- */

char	*gnl(const int fd);

#endif // TEST_PRINTF_H