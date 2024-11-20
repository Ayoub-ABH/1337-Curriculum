/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:25:16 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/18 15:17:39 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_shared_data(t_data *data, char **av)
{
	data->n_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->stop_sim = 0;
	data->n_full_philos = 0;
	if (av[5])
		data->n_times_to_eat = ft_atoi(av[5]);
	else
		data->n_times_to_eat = -1;
	return (1);
}

static int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (0);
	if (pthread_mutex_init(&data->print_lock, NULL))
		return (clean_locks(data, 1), 0);
	if (pthread_mutex_init(&data->stop_sim_lock, NULL))
		return (clean_locks(data, 2), 0);
	if (pthread_mutex_init(&data->meals_lock, NULL))
		return (clean_locks(data, 3), 0);
	if (pthread_mutex_init(&data->time_lock, NULL))
		return (clean_locks(data, 4), 0);
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (clean_forks(i, data->forks), free(data->forks), 0);
		i++;
	}
	return (1);
}

static int	init_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philos)
	{
		clean_locks(data, 4);
		clean_forks(data->n_philos, data->forks);
		free(data->forks);
		return (0);
	}
	while (++i < data->n_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].n_meals = 0;
		data->philos[i].last_time_eat = get_current_time();
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % data->n_philos];
	}
	return (1);
}

int	init_data(t_data *data, char **av)
{
	if (!init_shared_data(data, av))
		return (0);
	if (!init_forks(data))
		return (0);
	if (!init_philos(data))
		return (0);
	return (1);
}
