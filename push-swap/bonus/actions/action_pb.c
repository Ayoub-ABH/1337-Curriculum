/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:44:50 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/22 22:35:34 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	action_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (stack_a->top >= 0)
	{
		while (i < stack_b->size)
		{
			stack_b->args[stack_b->size - i] = stack_b->args
			[stack_b->size - i - 1];
			i++;
		}
		stack_b->args[0] = stack_a->args[0];
		stack_b->top += 1;
		while (j < stack_a->size)
		{
			stack_a->args[j - 1] = stack_a->args[j];
			j++;
		}
		stack_a->top -= 1;
	}
}
