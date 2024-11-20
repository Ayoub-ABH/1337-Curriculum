/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:38:07 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/28 22:49:42 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	int	max;
	int	min;

	max = a->args[i_max(a)];
	min = a->args[i_min(a)];
	if (a->args[0] == min && a->args[a->top] == max)
		return ;
	if (a->args[a->top] == min && a->args[a->top - 1] == max)
		action_rra(a, 1);
	else if (a->args[a->top] == max && a->args[a->top - 1] == min)
		action_sa(a, 1);
	else if (a->args[0] == max && a->args[a->top - 1] == min)
		action_ra(a, 1);
	else if (a->args[0] == max && a->args[a->top] == min)
	{
		action_ra(a, 1);
		action_sa(a, 1);
	}
	else
	{
		action_sa(a, 1);
		action_ra(a, 1);
	}
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (i_min(a) <= 1)
		while (a->args[0] != a->args[i_min(a)])
			action_ra(a, 1);
	else
		while (a->args[0] != a->args[i_min(a)])
			action_rra(a, 1);
	action_pb(a, b);
	sort_3(a);
	action_pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (i_min(a) <= 2)
		while (a->args[0] != a->args[i_min(a)])
			action_ra(a, 1);
	else
		while (a->args[0] != a->args[i_min(a)])
			action_rra(a, 1);
	action_pb(a, b);
	if (i_min(a) <= 2)
		while (a->args[0] != a->args[i_min(a)])
			action_ra(a, 1);
	else
		while (a->args[0] != a->args[i_min(a)])
			action_rra(a, 1);
	action_pb(a, b);
	sort_3(a);
	action_pa(a, b);
	action_pa(a, b);
}
