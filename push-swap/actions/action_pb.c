/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:44:50 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/23 23:06:13 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_pb(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (a->top >= 0)
	{
		while (i < b->size)
		{
			b->args[b->size - i] = b->args
			[b->size - i - 1];
			i++;
		}
		b->args[0] = a->args[0];
		b->top += 1;
		while (j < a->size)
		{
			a->args[j - 1] = a->args[j];
			j++;
		}
		a->top -= 1;
		write(1, "pb\n", 3);
	}
}
