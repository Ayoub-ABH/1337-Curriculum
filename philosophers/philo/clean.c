/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:29:13 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/14 16:01:52 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_forks(int n_philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	clean_locks(t_data *data, int n_locks)
{
	if (n_locks == 1)
		pthread_mutex_destroy(&data->print_lock);
	else if (n_locks == 2)
	{
		pthread_mutex_destroy(&data->print_lock);
		pthread_mutex_destroy(&data->stop_sim_lock);
	}
	else if (n_locks == 3)
	{
		pthread_mutex_destroy(&data->print_lock);
		pthread_mutex_destroy(&data->stop_sim_lock);
		pthread_mutex_destroy(&data->meals_lock);
	}
	else if (n_locks == 4)
	{
		pthread_mutex_destroy(&data->print_lock);
		pthread_mutex_destroy(&data->stop_sim_lock);
		pthread_mutex_destroy(&data->meals_lock);
		pthread_mutex_destroy(&data->time_lock);
	}
}

void	clean(t_data *data)
{
	clean_forks(data->n_philos, data->forks);
	clean_locks(data, 4);
	free(data->forks);
	free(data->philos);
}
