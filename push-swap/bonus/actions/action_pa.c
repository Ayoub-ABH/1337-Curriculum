/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:43:24 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/22 22:35:27 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	action_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (stack_b->top >= 0)
	{
		while (i < stack_a->size)
		{
			stack_a->args[stack_a->size - i] = stack_a->args
			[stack_a->size - i - 1];
			i++;
		}
		stack_a->args[0] = stack_b->args[0];
		stack_a->top += 1;
		while (j < stack_b->size)
		{
			stack_b->args[j - 1] = stack_b->args[j];
			j++;
		}
		stack_b->top -= 1;
	}
}
