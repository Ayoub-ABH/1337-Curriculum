/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:57:44 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/22 23:26:39 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	action_rrr(t_stack *stack_a, t_stack *stack_b)
{
	action_rra(stack_a);
	action_rrb(stack_b);
}
