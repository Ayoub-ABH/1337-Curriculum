/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:41:21 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/18 17:56:42 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philos)
{
	int		i;

	i = 0;
	while (i < philos->data->n_philos)
	{
		if (get_current_time() - get_last_time(philos[i]) >= \
			philos->data->time_to_die)
		{
			set_stop_sim(philos);
			printf("%ld %d died\n", get_current_time() - \
				philos->data->start_time, philos[i].id);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		if (get_n_f_phs(philos->data) == philos->data->n_philos)
		{
			set_stop_sim(philos);
			break ;
		}
		if (check_dead(philos))
			break ;
	}
	return (NULL);
}
