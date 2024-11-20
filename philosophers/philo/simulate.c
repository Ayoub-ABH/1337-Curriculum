/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:32:27 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/14 15:56:37 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulate(t_data *data)
{
	int	i;

	i = -1;
	if (data->n_times_to_eat == 0)
		return (0);
	else
	{
		data->start_time = get_current_time();
		while (++i < data->n_philos)
		{
			if (pthread_create(&data->philos[i].thread, NULL, &philo_routine, \
			&data->philos[i]))
				return (printf("error creating thread\n"), 0);
		}
		if (pthread_create(&data->monitor_t, NULL, &monitoring, data->philos))
			return (printf("error creating thread\n"), 0);
		i = -1;
		while (++i < data->n_philos)
			pthread_join(data->philos[i].thread, NULL);
		pthread_join(data->monitor_t, NULL);
	}
	return (1);
}
