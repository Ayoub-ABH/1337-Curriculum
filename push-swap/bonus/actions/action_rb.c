/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:47:58 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/24 14:17:52 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	action_rb(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->top > 0)
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
