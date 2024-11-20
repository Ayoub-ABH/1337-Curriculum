/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:09:14 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/24 14:38:28 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	is_digits_bs(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	count_args_bs(char **numbers, int *size)
{
	long	arg;
	int		j;

	j = 0;
	if (numbers[j] == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (numbers[j] != NULL)
	{
		if (!is_digits_bs(numbers[j]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		arg = ft_atol(numbers[j++]);
		if (arg > INT_MAX || arg < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		(*size)++;
	}
	return (1);
}

void	free_2d(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	parse_stack_bs(char **av)
{
	char	**numbers;
	int		size;
	int		i;

	size = 0;
	i = 1;
	while (av[i] != NULL)
	{
		numbers = ft_split(av[i], ' ');
		if (!count_args_bs(numbers, &size))
			return (0);
		free_2d(numbers);
		i++;
	}
	return (size);
}
