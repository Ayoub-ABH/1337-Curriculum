/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:17:30 by aait-bab          #+#    #+#             */
/*   Updated: 2023/10/01 13:36:53 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	arr = (int *) malloc(sizeof(int) * (max - min));
	if (arr == NULL)
		return (0);
	while (max > min)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
