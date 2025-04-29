/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:02:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/25 20:28:11 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// Prueba con cadenas
	const char *str = "Hola mundo";
	printf("Original: %s\n", str);
	int ret = ft_printf("Personalizado: %s\n", str);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con cadenas
	const char *str2 = "Hola mundo 1";
	const char *str3 = "/ Hola mundo/";
	printf("Original: %s %s\n", str2, str3);
	ret = ft_printf("Personalizado: %s %s\n", str2, str3);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con caracteres
	char c = 'A';
	printf("Original: %c\n", c);
	ret = ft_printf("Personalizado: %c\n", c);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con enteros
	int num = 42;
	printf("Original: %d\n", num);
	ret = ft_printf("Personalizado: %d\n", num);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con enteros negativos
	int neg = -12345;
	printf("Original: %d\n", neg);
	ret = ft_printf("Personalizado: %d\n", neg);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con unsigned
	unsigned int u = 4294967295;
	printf("Original: %u\n", u);
	ret = ft_printf("Personalizado: %u\n", u);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con hexadecimal en minúsculas
	unsigned int hex = 255;
	printf("Original: %x\n", hex);
	ret = ft_printf("Personalizado: %x\n", hex);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con hexadecimal en mayúsculas
	printf("Original: %X\n", hex);
	ret = ft_printf("Personalizado: %X\n", hex);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con el carácter '%'
	printf("Original: %%\n");
	ret = ft_printf("Personalizado: %%\n");
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con una cadena nula
	const char *null_str = NULL;
	printf("Original: %s\n", null_str);
	ret = ft_printf("Personalizado: %s\n", null_str);
	printf("ft_printf devolvió: %d\n", ret);

	return (0);
}