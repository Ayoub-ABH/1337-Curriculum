/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:17:42 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/22 23:27:50 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line_(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	i += (buffer[i] == '\n');
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	while (buffer[j] && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*get_remain(char *start)
{
	char	*remain;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!start)
		return (NULL);
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
		return (free(start), start = NULL, NULL);
	i += (start[i] == '\n');
	remain = malloc(ft_strlen_(start) - i + 1);
	if (!remain)
		return (NULL);
	while (start [i + j])
	{
		remain[j] = start[i + j];
		j++;
	}
	remain[j] = '\0';
	free(start);
	start = NULL;
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*remain[OPEN_MAX] = {NULL};
	char		*line_read;
	char		*line_returned;
	int			char_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	line_read = malloc(BUFFER_SIZE + 1);
	if (!line_read)
		return (free(remain[fd]), remain[fd] = NULL, NULL);
	char_read = 1;
	while (!(ft_strchr_(remain[fd], '\n')) && char_read != 0)
	{
		char_read = read(fd, line_read, BUFFER_SIZE);
		if (char_read == -1)
			return (free(line_read), free(remain[fd]), remain[fd] = NULL, NULL);
		line_read [char_read] = '\0';
		remain[fd] = ft_strjoin_(remain[fd], line_read);
	}
	free(line_read);
	line_returned = get_line_(remain[fd]);
	remain[fd] = get_remain(remain[fd]);
	return (line_returned);
}
