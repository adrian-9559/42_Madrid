/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: adriescr <adriescr@student.42madrid.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/05 19:00:20 by adriescr		  #+#	#+#			 */
/*   Updated: 2025/05/06 13:50:54 by adriescr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_remainder(char *remainder)
{
    char	*new_remainder;
    int		i;
    int		j;

    i = 0;
    while (remainder[i] && remainder[i] != '\n')
        i++;
    if (!remainder[i] || (remainder[i] == '\n' && remainder[i + 1] == '\0'))
    {
        free(remainder);
        return (NULL);
    }
    new_remainder = malloc((ft_strlen(remainder) - i) * sizeof(char));
    if (!new_remainder)
    {
        free(remainder);
        return (NULL);
    }
    i++;
    j = 0;
    while (remainder[i])
        new_remainder[j++] = remainder[i++];
    new_remainder[j] = '\0';
    free(remainder);
    return (new_remainder);
}

char	*ft_extract_line(char *remainder)
{
    char	*line;
    int		len;
    int		i;

    if (!remainder || !*remainder)
        return (NULL);
    len = 0;
    while (remainder[len] && remainder[len] != '\n')
        len++;
    line = malloc((len + (remainder[len] == '\n') + 1) * sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (i < len)
    {
        line[i] = remainder[i];
        i++;
    }
    if (remainder[len] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char	*handle_reading(int fd, char *remainder, t_gnl_vars vars)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, vars.buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(vars.buffer);
			free(remainder);
			return (NULL);
		}
		vars.buffer[bytes_read] = '\0';
		if (!remainder)
			remainder = ft_strdup(vars.buffer);
		else
		{
			temp = ft_strjoin(remainder, vars.buffer);
			if (!temp)
			{
				free(vars.buffer);
				free(remainder);
				return (NULL);
			}
			remainder = temp;
		}
		if (ft_strchr(vars.buffer, '\n'))
			break ;
	}
	free(vars.buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	t_gnl_vars	vars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	vars.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!vars.buffer)
		return (NULL);
	remainder = handle_reading(fd, remainder, vars);
	if (!remainder)
		return (NULL);
	vars.line = ft_extract_line(remainder);
	remainder = ft_update_remainder(remainder);
	return (vars.line);
}
