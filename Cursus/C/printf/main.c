/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:02:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/30 16:04:53 by adriescr         ###   ########.fr       */
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

	// Prueba con cadenas vacías
	const char *empty_str = "";
	printf("Original: %s\n", empty_str);
	ret = ft_printf("Personalizado: %s\n", empty_str);
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
	int original_ret2 = printf("Original: %x\n", hex);
	printf("Número de caracteres devueltos por printf: %d\n", original_ret2);
	ret = ft_printf("Personalizado: %x\n", hex);
	printf("Número de caracteres devueltos por ft_printf: %d\n", ret);

	// Prueba con hexadecimal en mayúsculas
	original_ret2 = printf("Original: %X\n", hex);
	printf("Número de caracteres devueltos por printf: %d\n", original_ret2);
	ret = ft_printf("Personalizado: %X\n", hex);
	printf("Número de caracteres devueltos por ft_printf: %d\n", ret);

	// Prueba con punteros
	void *ptr = &num;
	printf("Original: %p\n", ptr);
	ret = ft_printf("Personalizado: %p\n", ptr);
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

	// Prueba con múltiples formatos combinados
	printf("Original: %d %s %c %x %p %%\n", num, str, c, hex, ptr);
	ret = ft_printf("Personalizado: %d %s %c %x %p %%\n", num, str, c, hex, ptr);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con ancho mínimo
	printf("Original: %10d\n", num);
	ret = ft_printf("Personalizado: %10d\n", num);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con precisión
	printf("Original: %.5d\n", num);
	ret = ft_printf("Personalizado: %.5d\n", num);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con ancho y precisión combinados
	printf("Original: %10.5d\n", num);
	ret = ft_printf("Personalizado: %10.5d\n", num);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con alineación a la izquierda
	printf("Original: %-10d\n", num);
	ret = ft_printf("Personalizado: %-10d\n", num);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con ceros a la izquierda
	printf("Original: %010d\n", num);
	ret = ft_printf("Personalizado: %010d\n", num);
	printf("ft_printf devolvió: %d\n", ret);

	// Prueba con hexadecimal negativo con bonus %-x
	int neg_hex = -255;
	printf("Original: %-3x\n", neg_hex);
	int original_ret = printf("Original: %-3x\n", neg_hex);
	printf("Número de caracteres devueltos por printf: %d\n", original_ret);

	ret = ft_printf("Personalizado: %-3x\n", neg_hex);
	printf("Número de caracteres devueltos por ft_printf: %d\n", ret);

	printf("Original: %-3X\n", neg_hex);
	original_ret = printf("Original: %-3X\n", neg_hex);
	printf("Número de caracteres devueltos por printf: %d\n", original_ret);

	ret = ft_printf("Personalizado: %-3X\n", neg_hex);
	printf("Número de caracteres devueltos por ft_printf: %d\n", ret);

	return (0);
}
