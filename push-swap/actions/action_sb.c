/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:09:05 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/23 23:07:16 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_sb(t_stack *b, int print)
{
	int	tmp;

	if (b->size >= 2)
	{
		tmp = b->args[0];
		b->args[0] = b->args[1];
		b->args[1] = tmp;
		if (print)
			write(1, "sa\n", 3);
	}
	else
		return ;
}
