/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:43:24 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/23 23:05:54 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_pa(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (b->top >= 0)
	{
		while (i < a->size)
		{
			a->args[a->size - i] = a->args
			[a->size - i - 1];
			i++;
		}
		a->args[0] = b->args[0];
		a->top += 1;
		while (j < b->size)
		{
			b->args[j - 1] = b->args[j];
			j++;
		}
		b->top -= 1;
		write(1, "pa\n", 3);
	}
}
