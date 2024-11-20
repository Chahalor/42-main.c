/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:51:34 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/20 13:07:43 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include "../get_next_line.h"
#include "../get_next_line_bonus.h"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

#define TITLE(title) { \
	printf(YELLOW "/* ********************************* *\\\n"); \
	printf("|* ********| " title " |******* *|\n"); \
	printf("\\* ********************************* */\n" RESET); \
}

#define PART(title) { \
	printf("\n"); \
	printf(BLUE title "\n" RESET); \
}

#define	SAY_BUFFER_SIZE { \
	printf(BLUE "BUFFER_SIZE" RESET ": %i\n", BUFFER_SIZE); \
}

int errors = 0;
#define TEST(fd, expected) { \
	char	*res = get_next_line(fd); \
	if (BUFFER_SIZE <= 0 && !res) \
		printf(GREEN "OK " RESET); \
	else if (res && expected) \
		printf(GREEN "OK " RESET); \
	else if (!res && !expected) \
		printf(GREEN "OK " RESET); \
	else if (!res) \
		{printf(RED "KO, gnl return (null) " RESET); \
		errors++;} \
	else if (!expected) \
		{printf(RED "KO, expected (null), got %s " RESET, res); \
		errors++;} \
	free(res); \
}

/**
 * @file main_bonus.c
 * @brief Main file for testing get_next_line_bonus
 * @author nduvoid
 * @todo start/end at certaine test using arc/v flags
 * 
 * @param void No parameters (for now)
 */
int	main(int argc, const char **argv)
{
	(void)argc;
	(void)argv;
	SAY_BUFFER_SIZE
	
	PART("invalid fd");
	TEST(-1, NULL);			// 0.0

	PART("empty");
	int fd = open(".my_test/empty", O_RDONLY);
	int fd2 = open(".my_test/empty", O_RDONLY);
	TEST(fd, NULL);			// 1.0
	TEST(fd2, NULL);		// 1.1
	close(fd);
	close(fd2);
	
	PART("1char");
	fd = open(".my_test/1char", O_RDONLY);
	fd2 = open(".my_test/1char", O_RDONLY);
	TEST(fd, "0");			// 2.0
	TEST(fd2, "0");			// 2.1
	TEST(fd, NULL);			// 2.2
	TEST(fd2, NULL);		// 2.3
	close(fd);
	close(fd2);

	PART("one_line_no_nl");
	fd = open(".my_test/one_line_no_nl", O_RDONLY);
	fd2 = open(".my_test/one_line_no_nl", O_RDONLY);
	TEST(fd, "1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbn");		// 3.0
	TEST(fd2, "1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbn");	// 3.1
	TEST(fd, NULL);			// 3.2
	TEST(fd2, NULL);		// 3.3
	close(fd);
	close(fd2);

	PART("only_nl");
	fd = open(".my_test/only_nl", O_RDONLY);
	fd2 = open(".my_test/only_nl", O_RDONLY);
	TEST(fd, "\n");			// 4.0
	TEST(fd2, "\n");		// 4.1
	TEST(fd, NULL);			// 4.2
	TEST(fd2, NULL);		// 4.3
	close(fd);
	close(fd2);

	PART("multiple_nl");
	fd = open(".my_test/multiple_nl", O_RDONLY);
	fd2 = open(".my_test/multiple_nl", O_RDONLY);
	TEST(fd, "\n");			// 5.0
	TEST(fd2, "\n");		// 5.1
	TEST(fd, "\n");			// 5.2
	TEST(fd2, "\n");		// 5.3
	TEST(fd, "\n");			// 5.4
	TEST(fd2, "\n");		// 5.5
	TEST(fd, NULL);			// 5.6
	TEST(fd2, NULL);		// 5.7
	close(fd);
	close(fd2);
	
	PART("lines_around_10");
	fd = open(".my_test/lines_around_10", O_RDONLY);
	fd2 = open(".my_test/lines_around_10", O_RDONLY);
	TEST(fd, "0123456789\n");	// 6.0
	TEST(fd, "012345678\n");	// 6.1
	TEST(fd, "90123456789\n");	// 6.2
	TEST(fd, "0123456789\n");	// 6.3
	
	TEST(fd2, "0123456789\n")	// 6.4
	TEST(fd2, "012345678\n");	// 6.5
	TEST(fd2, "90123456789\n");	// 6.6
	TEST(fd, "xxxx\n");			// 6.7
	TEST(fd, NULL);				// 6.8
	TEST(fd2, "xxxx\n");		// 6.9
	TEST(fd2, NULL);			// 6.10
	close(fd);
	close(fd2);

	PART("limits fd");
	TEST(fd, NULL);			// 7.0
	TEST(INT_MAX, NULL);	// 7.1
	TEST(INT_MIN, NULL);	// 7.2
	TEST(fd, NULL);			// 7.3
	
	PART("closed fd");
	fd = open(".my_test/one_line_no_nl", O_RDONLY);
	fd2 = open(".my_test/one_line_no_nl", O_RDONLY);
	TEST(fd, "1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbn");		// 8.0
	close(fd);
	TEST(fd, NULL);												// 8.1
	TEST(fd2, "1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbn");	// 8.2
	close(fd2);
	TEST(fd2, NULL);											// 8.3
	
	if (!errors)
		printf(GREEN "All tests passed\n" RESET);
	else
		printf(RED "%i tests failed\n" RESET, errors);
	return (0);
}
