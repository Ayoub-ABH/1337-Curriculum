/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:17:25 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/29 00:10:53 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*init_stack_bs(int size)
{
	t_stack	*stack;

	if (size <= 0)
		return (NULL);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->args = (int *)malloc(sizeof(int) * size);
	if (stack->args == NULL)
		return (free(stack), NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

void	push_stack_bs(t_stack *stack, int value)
{
	if (stack->top < stack->size - 1)
		stack->args[++stack->top] = value;
}

void	pop_stack_bs(t_stack *stack)
{
	if (stack->top >= 0)
		stack->top--;
}

void	destroy_stack_bs(t_stack *stack)
{
	free(stack->args);
	free(stack);
}
