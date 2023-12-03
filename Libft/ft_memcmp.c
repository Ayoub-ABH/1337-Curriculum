/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:28:30 by aait-bab          #+#    #+#             */
/*   Updated: 2023/11/28 15:38:11 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s11;
	char	*s22;
	size_t	i;

	i = 0;
	s11 = (char *)s1;
	s22 = (char *)s2;
	while (i < n)
	{
		if (s11[i] != s22[i])
			return ((unsigned char)s11[i] - (unsigned char)s22[i]);
		i++;
	}
	return (0);
}
