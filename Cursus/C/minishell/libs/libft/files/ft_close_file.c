/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:25:57 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/22 12:48:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * ENGLISH: Closes a file descriptor.
 *
 * SPANISH: Cierra un descriptor de archivo.
 *
 * @param fd   The file descriptor to close. /
 *             El descriptor de archivo a cerrar.
 *
 * @returns 0 on success, or -1 on failure. /
 *          0 en caso de éxito, o -1 en caso de error.
 */
int	ft_close_file(int fd)
{
	if (close(fd) < 0)
		return (-1);
	return (0);
}
