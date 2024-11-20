/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:57:05 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/16 01:39:00 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_rrb(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	i = stack->top;
	if (stack->top > 0)
	{
		tmp = stack->args[stack->top];
		while (i > 0)
		{
			stack->args[i] = stack->args[i - 1];
			i--;
		}
		stack->args[0] = tmp;
		if (print)
			write(1, "rrb\n", 4);
	}
}
