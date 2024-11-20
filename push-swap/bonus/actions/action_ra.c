/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:45:24 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/22 22:35:44 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	action_ra(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->top >= 0)
	{
		tmp = stack->args[0];
		while (i < stack->top)
		{
			stack->args[i] = stack->args[i + 1];
			i++;
		}
		stack->args[stack->top] = tmp;
	}
}
