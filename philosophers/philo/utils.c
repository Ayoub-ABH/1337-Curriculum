/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:43:37 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/18 18:35:23 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numbers(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atoi(char *str)
{
	long	res;
	long	sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		sign = 44 - str[i++];
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		if (res >= INT_MAX && sign == 1)
			return (INT_MAX);
		if (res <= INT_MIN && sign == -1)
			return (INT_MIN);
		i++;
	}
	return (res * sign);
}

int	check_numbers(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0
			|| ft_atoi(av[i]) == INT_MAX
			|| ft_atoi(av[i]) == INT_MIN)
			return (0);
		if (i == 1)
			if (ft_atoi(av[1]) == 0 || ft_atoi(av[1]) > 200)
				return (0);
		if (i > 1 && i < 5)
			if (ft_atoi(av[i]) < 60)
				return (0);
		i++;
	}
	return (1);
}

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(long time, t_philo *philo)
{
	long	start;

	start = get_current_time();
	while ((get_current_time() - start) < time && get_stop_sim(philo) == 0)
		usleep(500);
	return (0);
}
