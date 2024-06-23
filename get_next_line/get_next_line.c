/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:29:24 by aait-bab          #+#    #+#             */
/*   Updated: 2024/01/23 22:56:24 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	remain = malloc(ft_strlen(start) - i + 1);
	if (!remain)
		return (free(start), start = NULL, NULL);
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
	static char	*remain = NULL;
	char		*line_read;
	char		*line_returned;
	int			char_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	line_read = malloc(BUFFER_SIZE + 1);
	if (!line_read)
		return (free(remain), remain = NULL, NULL);
	char_read = 1;
	while (!(ft_strchr(remain, '\n')) && char_read != 0)
	{
		char_read = read(fd, line_read, BUFFER_SIZE);
		if (char_read == -1)
			return (free(line_read), free(remain), remain = NULL, NULL);
		line_read [char_read] = '\0';
		remain = ft_strjoin(remain, line_read);
	}
	free(line_read);
	line_returned = get_line_(remain);
	remain = get_remain(remain);
	return (line_returned);
}
