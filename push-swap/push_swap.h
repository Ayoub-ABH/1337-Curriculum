/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:39:41 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/26 22:45:42 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*args;
	int	top;
	int	size;
}	t_stack;

t_stack	*init_stack(int size);
void	push_stack(t_stack *stack, int value);
void	pop_stack(t_stack *stack);
void	destroy_stack(t_stack *stack);
int		parse_stack(char **av);
int		is_sorted(t_stack *stack);
void	free_split(char **split);
t_stack	*fill_stack(int ac, char **av);
int		*get_liss(t_stack *a);
void	append_liss(t_stack *a, t_stack *b, int *lis);
int		get_cost_a(t_stack *a, int arg);
int		get_min_cost(t_stack *a, t_stack *b);
void	push_arg(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
int		get_min_arg(t_stack *a);
void	action_sa(t_stack *a, int print);
void	action_sb(t_stack *b, int print);
void	action_ss(t_stack *a, t_stack *b);
void	action_pa(t_stack *a, t_stack *b);
void	action_pb(t_stack *a, t_stack *b);
void	action_ra(t_stack *a, int print);
void	action_rb(t_stack *b, int print);
void	action_rr(t_stack *a, t_stack *b);
void	action_rra(t_stack *a, int print);
void	action_rrb(t_stack *b, int print);
void	action_rrr(t_stack *a, t_stack *b);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
int		i_min(t_stack *a);
int		i_max(t_stack *a);
int		i_btw(t_stack *a, int arg);
#endif