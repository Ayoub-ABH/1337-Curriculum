/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:45:00 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/18 15:34:13 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_stop_sim(t_philo *philo)
{
	int	value;

	pthread_mutex_lock(&philo->data->stop_sim_lock);
	value = philo->data->stop_sim;
	pthread_mutex_unlock(&philo->data->stop_sim_lock);
	return (value);
}

long	get_last_time(t_philo philo)
{
	long	value;

	pthread_mutex_lock(&philo.data->time_lock);
	value = philo.last_time_eat;
	pthread_mutex_unlock(&philo.data->time_lock);
	return (value);
}

int	get_n_f_phs(t_data *data)
{
	int	value;

	pthread_mutex_lock(&data->meals_lock);
	value = data->n_full_philos;
	pthread_mutex_unlock(&data->meals_lock);
	return (value);
}
