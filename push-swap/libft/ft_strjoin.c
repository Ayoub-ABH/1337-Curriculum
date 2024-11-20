/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:30:28 by aait-bab          #+#    #+#             */
/*   Updated: 2023/11/25 19:36:26 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concst;
	int		ls1;
	int		ls2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	concst = (char *)malloc(ls1 + ls2 + 1);
	if (concst == NULL)
		return (NULL);
	ft_memcpy(concst, s1, ls1);
	ft_memcpy (concst + ls1, s2, ls2);
	concst[ls2 + ls1] = '\0';
	return (concst);
}
