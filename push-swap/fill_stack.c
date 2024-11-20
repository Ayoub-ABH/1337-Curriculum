/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:11:41 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/28 22:19:51 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_args(char **av, t_stack *a)
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
			push_stack(a, arg);
			j++;
		}
		free_split(numbers);
		i++;
	}
}

int	is_contain_double(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->args[i] == a->args[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*a;

	if (ac >= 2)
	{
		a = init_stack(parse_stack(av));
		if (a == NULL)
			return (NULL);
		split_args(av, a);
		if (is_contain_double(a))
		{
			write(2, "Error\n", 6);
			return (destroy_stack(a), NULL);
		}
	}
	else
	{
		return (NULL);
	}
	return (a);
}
