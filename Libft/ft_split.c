/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:45:06 by aait-bab          #+#    #+#             */
/*   Updated: 2023/12/01 15:45:47 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**_free_all(char	**strings, int index)
{
	int	i;

	i = 0;
	while (index - i >= 0)
	{
		free(strings[index - i]);
		i++;
	}
	free(strings);
	return (NULL);
}

static int	_count_strings(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*_get_word(char const *str, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = 0;
	while (str[len_word] && str[len_word] != c)
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (word == NULL)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) 
			* (_count_strings(s, c) + 1));
	if (strings == NULL) 
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			strings[i] = _get_word(s, c);
			if (strings[i] == NULL)
				return (_free_all(strings, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	return (strings[i] = 0, strings);
}
