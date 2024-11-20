/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:47:30 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/20 13:07:49 by nduvoid          ###   ########.fr       */
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
 * @file main.c
 * @brief Main file for testing get_next_line
 * @author nduvoid
 * @todo start/end at certaine test using arc/v flags
 * 
 * @param void No parameters (for now)
 */
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	SAY_BUFFER_SIZE

	PART("Invalide fd");
	TEST(-1, NULL);			// 1
	TEST(INT_MAX, NULL);	// 2
	TEST(INT_MIN, NULL);	// 3

	PART("empty");
	int fd = open(".my_test/empty", O_RDONLY);
	TEST(fd, NULL);		// 1
	close(fd);

	PART("1char");
	fd = open(".my_test/1char", O_RDONLY);
	TEST(fd, "0");		// 1
	TEST(fd, NULL);		// 2
	close(fd);

	PART("one_line_no_nl");
	fd = open(".my_test/one_line_no_nl", O_RDONLY);
	TEST(fd, "1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbn");	// 1
	TEST(fd, NULL);		// 2
	close(fd);

	PART("only_nl");
	fd = open(".my_test/only_nl", O_RDONLY);
	TEST(fd, "\n");		// 1
	TEST(fd, NULL);		// 2
	close(fd);

	PART("multiple_nl");
	fd = open(".my_test/multiple_nl", O_RDONLY);
	TEST(fd, "\n");		// 1
	TEST(fd, "\n");		// 2
	TEST(fd, "\n");		// 3
	TEST(fd, NULL);		// 4
	close(fd);

	PART("lines_around_10");
	fd = open(".my_test/lines_around_10", O_RDONLY);
	TEST(fd, "0123456789\n");	// 1
	TEST(fd, "012345678\n");	// 2
	TEST(fd, "90123456789\n");	// 3
	TEST(fd, "0123456789\n");	// 4
	TEST(fd, "xxxx\n");			// 5
	TEST(fd, NULL);				// 6
	close(fd);

	PART("limits fd");
	TEST(fd, NULL);			// 1
	TEST(INT_MAX, NULL);	// 2
	TEST(INT_MIN, NULL);	// 3

	PART("closed fd");
	fd = open(".my_test/one_line_no_nl", O_RDONLY);
	TEST(fd, "1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbn");	// 1
	close(fd);
	TEST(fd, NULL);											// 2
	
	if (!errors)
		printf(GREEN "\nAll tests passed\n" RESET);
	else
		printf(RED "\n%d errors\n" RESET, errors);
	return (0);
}
