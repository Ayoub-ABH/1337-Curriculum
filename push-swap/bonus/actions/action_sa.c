/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:49:46 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/22 22:37:47 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	action_sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->size >= 2)
	{
		tmp = stack_a->args[0];
		stack_a->args[0] = stack_a->args[1];
		stack_a->args[1] = tmp;
	}
	else
		return ;
}
