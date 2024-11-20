/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:13:13 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/18 18:36:21 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 6 || ac < 5)
	{
		write(2, "Not a valid number of arguments\n", 32);
		return (0);
	}
	if (!is_numbers(av))
	{
		write(2, "Not a valid number\n", 19);
		return (0);
	}
	if (!check_numbers(av))
	{
		write(2, "Not a valid number\n", 19);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!valid_args(ac, av))
		return (0);
	if (!init_data(&data, av))
	{
		printf("Error initializing data\n");
		return (0);
	}
	simulate(&data);
	clean(&data);
	return (0);
}
