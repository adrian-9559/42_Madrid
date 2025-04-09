/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:38:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 17:09:30 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Incluye tu biblioteca personalizada
#include "libft.h"

void putstr_true(char *str)
{
    printf("\033[0;32m%s\033[0m\n", str);
}

void putstr_false(char *str)
{
    printf("\033[0;31m%s\033[0m\n", str);
}

void test_ft_atoi(void)
{
    char test_cases[][20] = {
        "42",
        "-42",
        "   42",
        "42abc",
        "abc42",
        "2147483647",
        "-2147483648",
        "2147483648", // Fuera de rango
        "-2147483649", // Fuera de rango
        "0",
        "",
        "\t\n\v\f\r 42"
    };
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_atoi:\n");
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        int original_result = atoi(test_cases[i]);
        int my_result = ft_atoi(test_cases[i]);

        // Mostrar el spinner
        printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (original_result == my_result)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void	test_ft_bzero(void)
{
	char test_cases[][20] = {
		"Hello, World!",
		"42 is the answer",
		"Libft is awesome!",
		"C programming",
		"Test case with null\0 character",
		"",
		"\0"
	};
	char spinner[] = "|/-\\"; // Carácter giratorio
	int spinner_index = 0;

	printf("Testing ft_bzero:\n");
	for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
	{
		char dest1[20];
		char dest2[20];
		strcpy(dest1, test_cases[i]);
		strcpy(dest2, test_cases[i]);
		bzero(dest1, strlen(test_cases[i]));
		ft_bzero(dest2, strlen(test_cases[i]));

		// Mostrar el spinner
		printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
		fflush(stdout); // Forzar la impresión inmediata
		spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
		usleep(200000); // Pausa de 200ms para simular carga

		// Comparar resultados
		if (strcmp(dest1, dest2) == 0)
			putstr_true(" Los resultados son iguales.\n");
		else
			putstr_false(" Los resultados son diferentes.\n");
	}
	printf("\n");
}

void test_ft_isalnum(void)
{
    char test_cases[] = {'a', 'z', 'A', 'Z', '1', '!', '\0'};
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_isalnum:\n");
    for (int i = 0; test_cases[i] != '\0'; i++)
    {
        int original_result = isalnum(test_cases[i]);
        int my_result = ft_isalnum(test_cases[i]);

        // Mostrar el spinner
        printf("\r%c Testing case '%c'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (original_result == 8 && my_result == 1  || original_result == my_result)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void test_ft_isalpha(void)
{
    char test_cases[] = {'a', 'z', 'A', 'Z', '1', '!', '\0'};
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_isalpha:\n");
    for (int i = 0; test_cases[i] != '\0'; i++)
    {
        int original_result = isalpha(test_cases[i]);
        int my_result = ft_isalpha(test_cases[i]);

        // Mostrar el spinner
        printf("\r%c Testing case '%c'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (original_result == 1024 && my_result == 1 || original_result == my_result)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void test_ft_isascii(void)
{
    char test_cases[] = {'a', 'z', 'A', 'Z', '1', '!', '\0'};
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_isascii:\n");
    for (int i = 0; test_cases[i] != '\0'; i++)
    {
        int original_result = isascii(test_cases[i]);
        int my_result = ft_isascii(test_cases[i]);

        // Mostrar el spinner
        printf("\r%c Testing case '%c'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (original_result == my_result)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void test_ft_isdigit(void)
{
    char test_cases[] = {'0', '5', '9', 'A', 'Z', 'a', 'z', '!', '\0'};
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_isdigit:\n");
    for (int i = 0; test_cases[i] != '\0'; i++)
    {
        int original_result = isdigit(test_cases[i]);
        int my_result = ft_isdigit(test_cases[i]);

        // Mostrar el spinner
        printf("\r%c Testing case '%c'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (original_result == 2048 && my_result == 1  || original_result == my_result)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void test_ft_isprint(void)
{
    char test_cases[] = {'a', 'z', 'A', 'Z', '1', '!', '\0'};
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_isprint:\n");
    for (int i = 0; test_cases[i] != '\0'; i++)
    {
        int original_result = isprint(test_cases[i]);
        int my_result = ft_isprint(test_cases[i]);

        // Mostrar el spinner
        printf("\r%c Testing case '%c'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (original_result == 16384 && my_result == 1)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void test_ft_memchr(void)
{
    char test_cases[][20] = {
        "Hello, World!",
        "42 is the answer",
        "Libft is awesome!",
        "C programming",
        "Test case with null\0 character",
        "",
        "\0"
    };
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_memchr:\n");
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        char *original_result = memchr(test_cases[i], 'o', strlen(test_cases[i]));
        char *my_result = ft_memchr(test_cases[i], 'o', strlen(test_cases[i]));

        // Mostrar el spinner
        printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (original_result == my_result)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void test_ft_memcmp(void)
{
    char test_cases[][20] = {
        "Hello, World!",
        "42 is the answer",
        "Libft is awesome!",
        "C programming",
        "Test case with null\0 character",
        "",
        "\0"
    };
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_memcmp:\n");
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        int original_result = memcmp(test_cases[i], test_cases[i], strlen(test_cases[i]));
        int my_result = ft_memcmp(test_cases[i], test_cases[i], strlen(test_cases[i]));

        // Mostrar el spinner
        printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (original_result == my_result)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void test_ft_memcpy(void)
{
    char test_cases[][20] = {
        "Hello, World!",
        "42 is the answer",
        "Libft is awesome!",
        "C programming",
        "Test case with null\0 character",
        "",
        "\0"
    };
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_memcpy:\n");
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        char dest1[20];
        char dest2[20];
        memcpy(dest1, test_cases[i], strlen(test_cases[i]) + 1);
        ft_memcpy(dest2, test_cases[i], strlen(test_cases[i]) + 1);

        // Mostrar el spinner
        printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (strcmp(dest1, dest2) == 0)
            putstr_true(" Los resultados son iguales.\n");
        else
            putstr_false(" Los resultados son diferentes.\n");
    }
    printf("\n");
}

void test_ft_memmove(void)
{
    char test_cases[][20] = {
        "Hello, World!",
        "42 is the answer",
        "Libft is awesome!",
        "C programming",
        "Test case with null\0 character",
        "",
        "\0"
    };
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_memmove:\n");
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        char dest1[20];
        char dest2[20];
        memmove(dest1, test_cases[i], strlen(test_cases[i]) + 1);
        ft_memmove(dest2, test_cases[i], strlen(test_cases[i]) + 1);

        // Mostrar el spinner
        printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (strcmp(dest1, dest2) == 0)
            putstr_true(" Los resultados son iguales.\n");
        else
            putstr_false(" Los resultados son diferentes.\n");
    }
    printf("\n");
}

void test_ft_memset(void)
{
    char test_cases[][20] = {
        "Hello, World!",
        "42 is the answer",
        "Libft is awesome!",
        "C programming",
        "Test case with null\0 character",
        "",
        "\0"
    };
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_memset:\n");
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        char dest1[20];
        char dest2[20];
        memset(dest1, 'X', strlen(test_cases[i]));
        ft_memset(dest2, 'X', strlen(test_cases[i]));

        // Mostrar el spinner
        printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (strcmp(dest1, dest2) == 0)
            putstr_true(" Los resultados son iguales.\n");
        else
            putstr_false(" Los resultados son diferentes.\n");
    }
    printf("\n");
}

void	test_ft_strchr(void)
{
	char test_cases[][20] = {
		"Hello, World!",
		"42 is the answer",
		"Libft is awesome!",
		"C programming",
		"Test case with null\0 character",
		"",
		"\0"
	};
	char spinner[] = "|/-\\"; // Carácter giratorio
	int spinner_index = 0;

	printf("Testing ft_strchr:\n");
	for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
	{
		char *original_result = strchr(test_cases[i], 'o');
		char *my_result = ft_strchr(test_cases[i], 'o');

		// Mostrar el spinner
		printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
		fflush(stdout); // Forzar la impresión inmediata
		spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
		usleep(200000); // Pausa de 200ms para simular carga

		// Comparar resultados
		if (original_result == my_result)
			putstr_true(" Los resultados son iguales.\n");
		else
			putstr_false(" Los resultados son diferentes.\n");
	}
	printf("\n");
}
#include <string.h>

void test_ft_strlcat(void)
{
    char test_cases[][20] = {
        "Hello, World!",
        "42 is the answer",
        "Libft is awesome!",
        "C programming",
        "Test case with null\0 character",
        "",
        "\0"
    };
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_strlcat:\n");
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        char dest1[40] = "Initial "; // Asegúrate de inicializar los buffers
        char dest2[40] = "Initial ";
        size_t ret1, ret2;

        // Llamar a las funciones
        ret1 = strlcat(dest1, test_cases[i], sizeof(dest1));
        ret2 = ft_strlcat(dest2, test_cases[i], sizeof(dest2));

        // Mostrar el spinner
        printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (ret1 == ret2 && strcmp(dest1, dest2) == 0)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original return: %zu, My return: %zu\n", ret1, ret2);
            printf("Original dest: '%s', My dest: '%s'\n", dest1, dest2);
        }
    }
    printf("\n");
}

void	test_ft_strlcpy(void)
{
    char test_cases[][20] = {
        "Hello, World!",
        "42 is the answer",
        "Libft is awesome!",
        "C programming",
        "Test case with null\0 character",
        "",
        "\0"
    };
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_strlcpy:\n");
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        char dest1[20];
        char dest2[20];
        strlcpy(dest1, test_cases[i], sizeof(dest1));
        ft_strlcpy(dest2, test_cases[i], sizeof(dest2));

        // Mostrar el spinner
        printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (strcmp(dest1, dest2) == 0)
            putstr_true(" Los resultados son iguales.\n");
        else
            putstr_false(" Los resultados son diferentes.\n");
    }
    printf("\n");
}

void	test_ft_strlen(void)
{
	char test_cases[][20] = {
		"Hello, World!",
		"42 is the answer",
		"Libft is awesome!",
		"C programming",
		"Test case with null\0 character",
		"",
		"\0"
	};
	char spinner[] = "|/-\\"; // Carácter giratorio
	int spinner_index = 0;

	printf("Testing ft_strlen:\n");
	for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
	{
		size_t original_result = strlen(test_cases[i]);
		size_t my_result = ft_strlen(test_cases[i]);

		// Mostrar el spinner
		printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
		fflush(stdout); // Forzar la impresión inmediata
		spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
		usleep(200000); // Pausa de 200ms para simular carga

		// Comparar resultados
		if (original_result == my_result)
			putstr_true(" Los resultados son iguales.\n");
		else
			putstr_false(" Los resultados son diferentes.\n");
	}
	printf("\n");
}

void	test_ft_strncmp(void)
{
	char test_cases[][20] = {
		"Hello, World!",
		"42 is the answer",
		"Libft is awesome!",
		"C programming",
		"Test case with null\0 character",
		"",
		"\0"
	};
	char spinner[] = "|/-\\"; // Carácter giratorio
	int spinner_index = 0;

	printf("Testing ft_strncmp:\n");
	for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
	{
		int original_result = strncmp(test_cases[i], test_cases[i], strlen(test_cases[i]));
		int my_result = ft_strncmp(test_cases[i], test_cases[i], strlen(test_cases[i]));

		// Mostrar el spinner
		printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
		fflush(stdout); // Forzar la impresión inmediata
		spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
		usleep(200000); // Pausa de 200ms para simular carga

		// Comparar resultados
		if (original_result == my_result)
			putstr_true(" Los resultados son iguales.\n");
		else
			putstr_false(" Los resultados son diferentes.\n");
	}
	printf("\n");
}

void	test_ft_strnstr(void)
{
	char test_cases[][20] = {
		"Hello, World!",
		"42 is the answer",
		"Libft is awesome!",
		"C programming",
		"Test case with null\0 character",
		"",
		"\0"
	};
	char spinner[] = "|/-\\"; // Carácter giratorio
	int spinner_index = 0;

	printf("Testing ft_strnstr:\n");
	for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
	{
		char *original_result = strnstr(test_cases[i], "o", strlen(test_cases[i]));
		char *my_result = ft_strnstr(test_cases[i], "o", strlen(test_cases[i]));

		// Mostrar el spinner
		printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
		fflush(stdout); // Forzar la impresión inmediata
		spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
		usleep(200000); // Pausa de 200ms para simular carga

		// Comparar resultados
		if (original_result == my_result)
			putstr_true(" Los resultados son iguales.\n");
		else
			putstr_false(" Los resultados son diferentes.\n");
	}
	printf("\n");
}

void	test_ft_strrchr(void)
{
	char test_cases[][20] = {
		"Hello, World!",
		"42 is the answer",
		"Libft is awesome!",
		"C programming",
		"Test case with null\0 character",
		"",
		"\0"
	};
	char spinner[] = "|/-\\"; // Carácter giratorio
	int spinner_index = 0;

	printf("Testing ft_strrchr:\n");
	for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
	{
		char *original_result = strrchr(test_cases[i], 'o');
		char *my_result = ft_strrchr(test_cases[i], 'o');

		// Mostrar el spinner
		printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
		fflush(stdout); // Forzar la impresión inmediata
		spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
		usleep(200000); // Pausa de 200ms para simular carga

		// Comparar resultados
		if (original_result == my_result)
			putstr_true(" Los resultados son iguales.\n");
		else
			putstr_false(" Los resultados son diferentes.\n");
	}
	printf("\n");
}

void test_ft_tolower(void)
{
    char test_cases[] = {'a', 'z', 'A', 'Z', '1', '!', '\0'};
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_tolower:\n");
    for (int i = 0; test_cases[i] != '\0'; i++)
    {
        char original_result = (char)tolower(test_cases[i]);
        char my_result = (char)ft_tolower(test_cases[i]);

        // Mostrar el spinner
        printf("\r%c Testing case '%c'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (original_result == my_result)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void test_ft_toupper(void)
{
    char test_cases[] = {'a', 'z', 'A', 'Z', '1', '!', '\0'};
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_toupper:\n");
    for (int i = 0; test_cases[i] != '\0'; i++)
    {
        char original_result = (char)toupper(test_cases[i]);
        char my_result = (char)ft_toupper(test_cases[i]);

        // Mostrar el spinner
        printf("\r%c Testing case '%c'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (original_result == my_result)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void    test_ft_calloc(void)
{
    char test_cases[][20] = {
        "Hello, World!",
        "42 is the answer",
        "Libft is awesome!",
        "C programming",
        "Test case with null\0 character",
        "",
        "\0"
    };
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_calloc:\n");
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        char *original_result = (char *)calloc(1, strlen(test_cases[i]) + 1);
        char *my_result = (char *)ft_calloc(1, strlen(test_cases[i]) + 1);

        // Mostrar el spinner
        printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (strcmp(original_result, my_result) == 0)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

void    test_ft_strdup(void)
{
    char test_cases[][20] = {
        "Hello, World!",
        "42 is the answer",
        "Libft is awesome!",
        "C programming",
        "Test case with null\0 character",
        "",
        "\0"
    };
    char spinner[] = "|/-\\"; // Carácter giratorio
    int spinner_index = 0;

    printf("Testing ft_strdup:\n");
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        char *original_result = strdup(test_cases[i]);
        char *my_result = ft_strdup(test_cases[i]);

        // Mostrar el spinner
        printf("\r%c Testing case '%s'...", spinner[spinner_index], test_cases[i]);
        fflush(stdout); // Forzar la impresión inmediata
        spinner_index = (spinner_index + 1) % 4; // Cambiar al siguiente carácter del spinner
        usleep(200000); // Pausa de 200ms para simular carga

        // Comparar resultados
        if (strcmp(original_result, my_result) == 0)
            putstr_true(" Los resultados son iguales.\n");
        else {
            putstr_false(" Los resultados son diferentes.\n");
            printf("Original result: %d\n", original_result);
            printf("My result: %d\n", my_result);
        }
    }
    printf("\n");
}

int main(void)
{
	int i;

	i = 0;
	printf("Testing Libft functions:\n");
    test_ft_atoi();
    i++;
    test_ft_bzero();
    i++;
    test_ft_isalnum();
    i++;
    test_ft_isalpha();
    i++;
    test_ft_isascii();
    i++;
    test_ft_isdigit();
    i++;
    test_ft_isprint();
    i++;
    test_ft_memchr();
    i++;
    test_ft_memcmp();
    i++;
    test_ft_memcpy();
    i++;
    test_ft_memmove();
    i++;
    test_ft_memset();
    i++;
    test_ft_strchr();
    i++;
    test_ft_strlcat();
    i++;
    test_ft_strlcpy();
    i++;
    test_ft_strlen();
    i++;
    test_ft_strncmp();
    i++;
    test_ft_strnstr();
    i++;
    test_ft_strrchr();
    i++;
    test_ft_tolower();
    i++;
    test_ft_toupper();
    i++;
    test_ft_calloc();
    i++;
    test_ft_strdup();
    i++;

	printf("\n");
	printf("Total tests run: %d\n", i);
	return (0);
}
