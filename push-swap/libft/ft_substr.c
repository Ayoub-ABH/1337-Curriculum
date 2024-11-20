/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:59:30 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/24 02:18:35 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_cal_finish(size_t *finish, size_t slen,
			size_t len, unsigned int start)
{
	if (start < slen)
		*finish = slen - (size_t)start;
	if (*finish > len)
		*finish = len;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*subst;
	size_t			finish;
	size_t			slen;

	if (s == NULL)
		return (NULL);
	finish = 0;
	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	_cal_finish(&finish, slen, len, start);
	subst = (char *)malloc(finish + 1);
	if (subst == NULL)
		return (NULL);
	while (i < finish)
	{
		subst[i] = s[start];
		i++;
		start++;
	}
	subst[finish] = '\0';
	return (subst);
}
