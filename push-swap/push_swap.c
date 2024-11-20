/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:26:52 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/29 00:09:54 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case(t_stack *a, t_stack *b)
{
	int		*lis;

	if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
	{
		lis = get_liss(a);
		append_liss(a, b, lis);
		free(lis);
		sort_stack(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = fill_stack(ac, av);
	if (!a)
		return (0);
	if (is_sorted(a))
		return (destroy_stack(a), 0);
	b = init_stack(a->size);
	if (!b)
		return (destroy_stack(a), 0);
	sort_case(a, b);
	destroy_stack(a);
	destroy_stack(b);
	return (0);
}
