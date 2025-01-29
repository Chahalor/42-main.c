/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:10:56 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/20 10:07:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

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

#define TEST(format, ...) { \
	printf("\n"); \
	int ret = ft_printf(format, ##__VA_ARGS__); \
	printf("\n"); \
	int ret2 = printf(format, ##__VA_ARGS__); \
	printf("\nDiff output :\t"); \
	if (ret == ret2) \
		printf(GREEN "OK" RESET); \
	else \
		printf(RED "KO" RESET); \
	printf("\n"); \
}

/**
 * @brief main function, test ft_printf for %s, %p, %d, %i, %u, %x, %X, %%
 * @author nduvoid
 */
int	main(int argc, const char *argv[])
{
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wformat"	// ignore warning for format string

	TITLE("MANDATORY PART")
	printf("\n");
	PART("/* ========== Start of tests ========== *\\");
	/* no % */
	PART("/* No %% */");
	TEST("Hello, world!");
	TEST("Hello, world!", 42);

	/* %c */
	PART("/* %%c */");
	TEST("char: %c", 'c');
	TEST("char: %c", 42);
	TEST("char: %c");

	/* %s */
	PART("/* %%s */");
	TEST("string: %s", "Hello, world!");
	TEST("string: %s", NULL);
	TEST("string: %s");
	TEST("");
	
	/* %p */
	PART("/* %%p */");
	TEST("pointer: %p", &argc);
	TEST("pointer: %p", NULL);
	TEST("pointer: %p");

	/* %d */
	PART("/* %%d */");
	TEST("decimal: %d", 42);
	TEST("decimal: %d", -42);
	TEST("decimal: %d", 0);
	TEST("decimal: %d");
	TEST("decimal: %d", INT_MAX);
	TEST("decimal: %d", INT_MIN);

	/* %i */
	PART("/* %%i */");
	TEST("integer: %i", 42);
	TEST("integer: %i", -42);
	TEST("integer: %i", 0);
	TEST("integer: %i");
	TEST("integer: %i", INT_MAX);
	TEST("integer: %i", INT_MIN);

	/* %u */
	PART("/* %%u */");
	TEST("unsigned: %u", 42);
	TEST("unsigned: %u", 0);
	TEST("unsigned: %u");
	TEST("unsigned: %u", UINT_MAX);
	
	/* %x */
	PART("/* %%x */");
	TEST("hex: %x", 42);
	TEST("hex: %x", 0);
	TEST("hex: %x");
	TEST("hex: %x", UINT_MAX);
	TEST("hex: %x", INT_MIN);
	
	/* %X */
	PART("/* %%X */");
	TEST("hex: %X", 42);
	TEST("hex: %X", 0);
	TEST("hex: %X");
	TEST("hex: %X", UINT_MAX);
	TEST("hex: %X", INT_MIN);

	/* %% */
	PART("/* %% */");
	TEST("percent: %%");
	TEST("percent: %%", 42);

	/* Undefind Beavore */
	PART("/* Undefind Beavore */");
	TEST("%% end of str : %");
	TEST("invalide %% : %w");

	PART("\\* ========== End of tests ========== */\n\n");
	
	if (argc == 1)
		return (0);
	
	TITLE("BONUS PART")
	printf("\n");
	PART("/* ========== Start of tests ========== *\\");
	PART("/* %%c */");
	TEST("char: %-c", 'c');
	TEST("char: %0c", 'c');
	TEST("char: %10c", 'c');
	TEST("char: %.c", 'c');
	TEST("char: %#c", 'c');
	TEST("char: %+c", 'c');
	TEST("char: % c", 'c');
	TEST("char: %-10.c", 'c');
	TEST("char: %# +c", 'c');
	TEST("char: %0-+ 10.c");

	PART("/* %%s */");
	TEST("string: %-s", "Hello, world!");
	TEST("string: %0s", "Hello, world!");
	TEST("string: %10s", "Hello, world!");
	TEST("string: %.s", "Hello, world!");
	TEST("string: %#s", "Hello, world!");
	TEST("string: %+s", "Hello, world!");
	TEST("string: % s", "Hello, world!");
	TEST("string: %-10.s", "Hello, world!");
	TEST("string: %# +s", "Hello, world!");
	TEST("string: %0-+ 10.s", "Hello, world!");

	PART("/* %%p */");
	TEST("pointer: %-p", &argc);
	TEST("pointer: %0p", &argc);
	TEST("pointer: %10p", &argc);
	TEST("pointer: %.p", &argc);
	TEST("pointer: %#p", &argc);
	TEST("pointer: %+p", &argc);
	TEST("pointer: % p", &argc);
	TEST("pointer: %-10.p", &argc);
	TEST("pointer: %# +p", &argc);

	PART("/* %%d */");
	TEST("decimal: %-d", 42);
	TEST("decimal: %0d", 42);
	TEST("decimal: %10d", 42);
	TEST("decimal: %.d", 42);
	TEST("decimal: %#d", 42);
	TEST("decimal: %+d", 42);
	TEST("decimal: % d", 42);
	TEST("decimal: %-10.d", 42);
	TEST("decimal: %# +d", 42);

	PART("/* %%i */");
	TEST("integer: %-i", 42);
	TEST("integer: %0i", 42);
	TEST("integer: %10i", 42);
	TEST("integer: %.i", 42);
	TEST("integer: %#i", 42);
	TEST("integer: %+i", 42);
	TEST("integer: % i", 42);
	TEST("integer: %-10.i", 42);
	TEST("integer: %# +i", 42);

	PART("/* %%u */");
	TEST("unsigned: %-u", 42);
	TEST("unsigned: %0u", 42);
	TEST("unsigned: %10u", 42);
	TEST("unsigned: %.u", 42);
	TEST("unsigned: %#u", 42);
	TEST("unsigned: %+u", 42);
	TEST("unsigned: % u", 42);
	TEST("unsigned: %-10.u", 42);
	TEST("unsigned: %# +u", 42);

	PART("/* %%x */");
	TEST("hex: %-x", 42);
	TEST("hex: %0x", 42);
	TEST("hex: %10x", 42);
	TEST("hex: %.x", 42);
	TEST("hex: %#x", 42);
	TEST("hex: %+x", 42);
	TEST("hex: % x", 42);
	TEST("hex: %-10.x", 42);

	PART("/* %%X */");
	TEST("hex: %-X", 42);
	TEST("hex: %0X", 42);
	TEST("hex: %10X", 42);
	TEST("hex: %.X", 42);
	TEST("hex: %#X", 42);
	TEST("hex: %+X", 42);
	TEST("hex: % X", 42);
	TEST("hex: %-10.X", 42);
	
	PART("/* %% */");
	TEST("percent: %%");
	
	PART("/* Undefind Beavore */");
	TEST("%% end of str : %");
	TEST("invalide %% : %-w");
	TEST("invalide %% : %0w");
	TEST("invalide %% : %10w");
	TEST("invalide %% : %.w");
	TEST("invalide %% : %#w");
	TEST("invalide %% : %+w");
	TEST("invalide %% : % w");
	TEST("invalide %% : %-10.w");
	TEST("invalide %% : %# +w");
	
	PART("\\* ========== End of tests ========== */");
	#pragma clang diagnostic pop
	return (0);
}
