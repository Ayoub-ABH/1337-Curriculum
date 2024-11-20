/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:13:10 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/29 00:11:06 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	valid_act(char *act)
{
	if (ft_strcmp(act, "sa\n") == 0 || ft_strcmp(act, "sb\n") == 0
		|| ft_strcmp(act, "ss\n") == 0 || ft_strcmp(act, "pa\n") == 0
		|| ft_strcmp(act, "pb\n") == 0 || ft_strcmp(act, "ra\n") == 0
		|| ft_strcmp(act, "rb\n") == 0 || ft_strcmp(act, "rr\n") == 0
		|| ft_strcmp(act, "rra\n") == 0 || ft_strcmp(act, "rrb\n") == 0
		|| ft_strcmp(act, "rrr\n") == 0)
		return (1);
	return (0);
}

int	error_act(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	destroy_stack_bs(a);
	destroy_stack_bs(b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*actions;
	char	*act;

	a = fill_stack_bs(ac, av);
	if (!a)
		return (0);
	b = init_stack_bs(a->size);
	if (!b)
		return (destroy_stack_bs(a), 0);
	while (1)
	{
		act = get_next_line(0);
		if (!act)
			break ;
		if (!valid_act(act))
			return (error_act(a, b));
		ft_lstadd_back(&actions, ft_lstnew(act));
	}
	free(act);
	execute_acts(actions, a, b);
	return (0);
}
