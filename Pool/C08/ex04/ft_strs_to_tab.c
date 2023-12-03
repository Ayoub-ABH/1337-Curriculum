/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:27:28 by aait-bab          #+#    #+#             */
/*   Updated: 2023/10/03 18:33:57 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(len(src) * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			l;
	int			i;
	t_stock_str	*t;

	t = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		l = len(*(av + i));
		(t + i)->size = l;
		(t + i)->str = *(av + i);
		(t + i)->copy = ft_strdup(*(av + i));
		i++;
	}
	(t + i)->str = 0;
	return (t);
}
