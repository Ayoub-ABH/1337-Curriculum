/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:45:09 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/18 18:37:05 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_time(t_philo philo)
{
	pthread_mutex_lock(&philo.data->time_lock);
	philo.last_time_eat = get_current_time();
	pthread_mutex_unlock(&philo.data->time_lock);
}

void	set_stop_sim(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_sim_lock);
	philo->data->stop_sim = 1;
	pthread_mutex_unlock(&philo->data->stop_sim_lock);
}

void	set_n_f_phs(t_data *data)
{
	pthread_mutex_lock(&data->meals_lock);
	data->n_full_philos++;
	pthread_mutex_unlock(&data->meals_lock);
}
