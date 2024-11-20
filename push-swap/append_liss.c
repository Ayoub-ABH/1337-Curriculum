/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_liss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:35:48 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/24 12:24:26 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_lis(int *lis, int n, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (n == lis[j])
			return (1);
		j++;
	}
	return (0);
}

int	moy_arg(t_stack *a)
{
	int	max;
	int	min;

	max = a->args[i_max(a)];
	min = a->args[i_min(a)];
	return ((max + min) / 2);
}

void	fill_b(t_stack *a, t_stack *b, int *lis, int *tmp)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (in_lis(lis, tmp[i], lis[a->size - 1]))
			action_ra(a, 1);
		else
		{
			if (tmp[i] <= moy_arg(a))
				action_pb(a, b);
			else
			{
				action_pb(a, b);
				action_rb(b, 1);
			}
		}
		i++;
	}
}

void	append_liss(t_stack *a, t_stack *b, int *lis)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	j = 0;
	tmp = malloc(a->size * sizeof(int));
	if (!tmp)
		return ;
	while (j < a->size)
	{
		tmp[j] = a->args[j];
		j++;
	}
	fill_b(a, b, lis, tmp);
	free(tmp);
}
