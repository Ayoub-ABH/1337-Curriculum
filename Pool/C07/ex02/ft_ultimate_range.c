/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:37:32 by aait-bab          #+#    #+#             */
/*   Updated: 2023/10/01 13:40:56 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;
	int	rn;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	rn = max - min;
	arr = (int *) malloc(sizeof(int) * rn);
	if (arr == NULL)
		return (-1);
	while (max > min)
	{
		arr[i] = min;
		min++;
		i++;
	}
	*range = arr;
	if (*range == NULL)
		return (-1);
	return (rn);
}
