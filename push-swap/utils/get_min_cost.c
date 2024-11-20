/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:29:58 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/23 23:54:39 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_cost_a(t_stack *a, int arg)
{
	if (arg < a->args[i_min(a)])
	{
		if (i_min(a) <= a->top / 2)
			return (i_min(a) + 1);
		else
			return (a->top - i_min(a) + 2);
	}
	else if (i_btw(a, arg) != -1)
	{
		if (i_btw(a, arg) <= a->top / 2)
			return (i_btw(a, arg) + 1);
		else
			return (a->top - i_btw(a, arg) + 2);
	}
	else if (arg > a->args[i_max(a)])
	{
		if (i_max(a) <= a->top / 2)
			return (i_max(a) + 1);
		else
			return (a->top - i_max(a) + 2);
	}
	else
		return (1);
	return (0);
}

int	get_cost_b(t_stack *b, int index)
{
	if (index <= b->top / 2)
		return (index + 1);
	else
		return (b->top - index + 2);
}

int	get_min_cost(t_stack *a, t_stack *b)
{
	int	index;
	int	cost;
	int	min;
	int	i;

	i = 0;
	index = 0;
	min = get_cost_a(a, b->args[0]) + get_cost_b(b, 0);
	while (i <= b->top)
	{
		cost = get_cost_a(a, b->args[i]) + get_cost_b(b, i);
		if (cost < min)
		{
			min = cost;
			index = i;
		}
		i++;
	}
	return (index);
}
