/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:15:45 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/28 23:14:45 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	split_args_bs(char **av, t_stack *stack_a)
{
	char	**numbers;
	long	arg;
	int		i;
	int		j;

	i = 1;
	while (av[i] != NULL)
	{
		numbers = ft_split(av[i], ' ');
		j = 0;
		while (numbers[j] != NULL)
		{
			arg = ft_atol(numbers[j]);
			push_stack_bs(stack_a, arg);
			j++;
		}
		free_2d(numbers);
		i++;
	}
}

int	is_contain_dble_bs(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->size)
	{
		j = i + 1;
		while (j < stack_a->size)
		{
			if (stack_a->args[i] == stack_a->args[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack	*fill_stack_bs(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac >= 2)
	{
		stack_a = init_stack_bs(parse_stack_bs(av));
		if (stack_a == NULL)
			return (NULL);
		split_args_bs(av, stack_a);
		if (is_contain_dble_bs(stack_a))
		{
			write(2, "Error\n", 6);
			return (destroy_stack_bs(stack_a), NULL);
		}
	}
	else
	{
		return (NULL);
	}
	return (stack_a);
}
