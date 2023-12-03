/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:37:57 by aait-bab          #+#    #+#             */
/*   Updated: 2023/10/02 19:36:00 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

int	get_size(char **strings, int size, int sep_length)
{
	int	final_length;
	int	i;

	final_length = 0;
	i = 0;
	while (i < size)
	{
		final_length += len(*(strings + i));
		final_length += sep_length;
		i++;
	}
	final_length -= sep_length;
	return (final_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		full_length;
	int		i;
	char	*d;
	char	*str;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	full_length = get_size(strs, size, len(sep));
	str = (char *)malloc((full_length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	d = str;
	i = 0;
	while (i < size - 1)
	{
		ft_strcpy(d, *(strs + i));
		d += len(*(strs + i));
		ft_strcpy(d, sep);
		d += len(sep);
		i++;
	}
	ft_strcpy(d, *(strs + i));
	d += len(*(strs + i));
	*d = '\0';
	return (str);
}
