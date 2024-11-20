/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_acts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:15:49 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/24 13:39:05 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	exe_act(char *act, t_stack *a, t_stack *b)
{
	if (ft_strcmp(act, "sa\n") == 0)
		action_sa(a);
	else if (ft_strcmp(act, "sb\n") == 0)
		action_sb(b);
	else if (ft_strcmp(act, "ss\n") == 0)
		action_ss(a, b);
	else if (ft_strcmp(act, "pa\n") == 0)
		action_pa(a, b);
	else if (ft_strcmp(act, "pb\n") == 0)
		action_pb(a, b);
	else if (ft_strcmp(act, "ra\n") == 0)
		action_ra(a);
	else if (ft_strcmp(act, "rb\n") == 0)
		action_rb(b);
	else if (ft_strcmp(act, "rr\n") == 0)
		action_rr(a, b);
	else if (ft_strcmp(act, "rra\n") == 0)
		action_rra(a);
	else if (ft_strcmp(act, "rrb\n") == 0)
		action_rrb(b);
	else if (ft_strcmp(act, "rrr\n") == 0)
		action_rrr(a, b);
}

void	execute_acts(t_list *actions, t_stack *a, t_stack *b)
{
	t_list	*tmp;

	tmp = actions;
	while (tmp)
	{
		exe_act(tmp->content, a, b);
		tmp = tmp->next;
	}
	if (is_sorted_bs(a) && b->top == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&actions, free);
	destroy_stack_bs(a);
	destroy_stack_bs(b);
}
