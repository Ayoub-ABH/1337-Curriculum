/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:10:11 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/29 00:01:08 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "./get_next_line/get_next_line_bonus.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*args;
	int	top;
	int	size;
}	t_stack;

t_stack	*init_stack_bs(int size);
void	push_stack_bs(t_stack *stack, int value);
void	pop_stack_bs(t_stack *stack);
void	destroy_stack_bs(t_stack *stack);

t_stack	*fill_stack_bs(int ac, char **av);
int		parse_stack_bs(char **av);

int		is_sorted_bs(t_stack *stack);
void	execute_acts(t_list *actions, t_stack *a, t_stack *b);
int		ft_strcmp(const char *s1, const char *s2);
void	free_2d(char **numbers);
void	action_sa(t_stack *stack_a);
void	action_sb(t_stack *stack_b);
void	action_ss(t_stack *stack_a, t_stack *stack_b);

void	action_pa(t_stack *stack_a, t_stack *stack_b);
void	action_pb(t_stack *stack_a, t_stack *stack_b);

void	action_ra(t_stack *stack_a);
void	action_rb(t_stack *stack_b);
void	action_rr(t_stack *stack_a, t_stack *stack_b);

void	action_rra(t_stack *stack_a);
void	action_rrb(t_stack *stack_b);
void	action_rrr(t_stack *stack_a, t_stack *stack_b);
#endif