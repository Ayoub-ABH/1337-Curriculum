/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:58:05 by aait-bab          #+#    #+#             */
/*   Updated: 2023/11/28 15:46:11 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	sd;
	size_t	ss;

	if ((dstsize == 0 && !dst) || dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = 0;
	sd = ft_strlen(dst);
	j = sd;
	ss = ft_strlen(src); 
	while (src[i] && i < dstsize - sd - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (sd + ss);
}
