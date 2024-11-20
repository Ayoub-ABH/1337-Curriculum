/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:54:20 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/24 02:33:57 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	p_min(t_stack *a, t_stack *b)
{
	if (i_min(a) <= a->top / 2)
	{
		while (a->args[0] != a->args[i_min(a)])
			action_ra(a, 1);
		action_pa(a, b);
	}
	else
	{
		while (a->args[0] != a->args[i_min(a)])
			action_rra(a, 1);
		action_pa(a, b);
	}
}

void	p_btw(t_stack *a, t_stack *b)
{
	int	arg;

	arg = a->args[i_btw(a, b->args[0])];
	if (i_btw(a, b->args[0]) <= a->top / 2)
	{
		while (a->args[0] != arg)
			action_ra(a, 1);
		action_pa(a, b);
	}
	else
	{
		while (a->args[0] != arg)
			action_rra(a, 1);
		action_pa(a, b);
	}
}

void	p_max(t_stack *a, t_stack *b)
{
	if (i_max(a) <= a->top / 2)
	{
		while (a->args[0] != a->args[i_min(a)])
			action_ra(a, 1);
		action_pa(a, b);
	}
	else
	{
		while (a->args[0] != a->args[i_min(a)])
			action_rra(a, 1);
		action_pa(a, b);
	}
}

void	push_arg(t_stack *a, t_stack *b)
{
	if (b->args[0] < a->args[i_min(a)])
	{
		p_min(a, b);
	}
	else if (i_btw(a, b->args[0]) != -1)
	{
		p_btw(a, b);
	}
	else if (b->args[0] > a->args[i_max(a)])
	{
		p_max(a, b);
	}
	else
	{
		action_pa(a, b);
	}
}
