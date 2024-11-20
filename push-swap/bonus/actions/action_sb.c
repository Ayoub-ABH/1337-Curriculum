/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:09:05 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/22 22:37:15 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	action_sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size >= 2)
	{
		tmp = stack_b->args[0];
		stack_b->args[0] = stack_b->args[1];
		stack_b->args[1] = tmp;
	}
	else
		return ;
}
