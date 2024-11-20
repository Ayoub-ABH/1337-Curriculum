/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:25:13 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/24 00:42:50 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_arg(t_stack *a)
{
	int	index;
	int	min;
	int	i;

	min = a->args[0];
	i = 0;
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

void	sort_stack(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (b->top >= 0)
	{
		if (get_min_cost(a, b) <= b->top / 2)
		{
			while (b->args[0] != b->args[get_min_cost(a, b)])
				action_rb(b, 1);
		}
		else
		{
			while (b->args[0] != b->args[get_min_cost(a, b)])
				action_rrb(b, 1);
		}
		push_arg(a, b);
	}
	if (get_min_arg(a) <= a->top / 2)
		while (a->args[0] != a->args[get_min_arg(a)])
			action_ra(a, 1);
	else
		while (a->args[0] != a->args[get_min_arg(a)])
			action_rra(a, 1);
}
