/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:00:39 by aait-bab          #+#    #+#             */
/*   Updated: 2023/11/28 14:58:09 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	char		*sourc;
	size_t		i;

	dest = (char *)dst;
	sourc = (char *)src;
	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (dest > sourc)
	{
		while (len--)
			dest[len] = sourc[len];
	}
	else
	{
		while (i < len)
		{
			dest[i] = sourc[i];
			i++;
		}
	}
	return (dst);
}
