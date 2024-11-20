/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:49:46 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/23 23:07:05 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_sa(t_stack *a, int print)
{
	int	tmp;

	if (a->size >= 2)
	{
		tmp = a->args[0];
		a->args[0] = a->args[1];
		a->args[1] = tmp;
		if (print)
			write(1, "sa\n", 3);
	}
	else
		return ;
}
