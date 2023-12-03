/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:50:10 by aait-bab          #+#    #+#             */
/*   Updated: 2023/11/29 19:16:19 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*trimstr;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_in_set(((char)*s1), set) == 1)
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1);
	while (size != 0)
	{
		if (ft_in_set(s1[size - 1], set) == 1)
			size--;
		else
			break ;
	}
	trimstr = (char *)malloc(size * sizeof(char) + 1);
	if (trimstr == NULL)
		return (NULL);
	ft_strlcpy(trimstr, (char *)s1, size + 1);
	return (trimstr);
}
