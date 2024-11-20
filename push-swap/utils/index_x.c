/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 02:20:30 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/24 02:23:58 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	i_min(t_stack *a)
{
	int	index;	
	int	min;
	int	i;

	i = 0;
	index = 0;
	min = a->args[0];
	while (i <= a->top)
	{
		if (a->args[i] <= min)
		{
			min = a->args[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	i_max(t_stack *a)
{
	int	index;
	int	max;
	int	i;

	i = 0;
	index = 0;
	max = a->args[0];
	while (i <= a->top)
	{
		if (a->args[i] >= max)
		{
			max = a->args[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	i_btw(t_stack *a, int arg)
{
	int	i;

	i = 1;
	while (i <= a->top)
	{
		if (a->args[i - 1] < arg && arg < a->args[i])
			return (i);
		i++;
	}
	return (-1);
}
