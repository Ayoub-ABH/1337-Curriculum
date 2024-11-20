/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:52:42 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/18 18:36:56 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print(t_philo *philo, char *msg)
{
	long	time;

	pthread_mutex_lock(&philo->data->print_lock);
	if (!get_stop_sim(philo))
	{
		time = get_current_time() - philo->data->start_time;
		printf("%ld %d %s\n", time, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}

static void	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print(philo, "has taken a fork");
}

static void	ft_eat(t_philo *philo)
{
	print(philo, "is eating");
	if (philo->data->n_times_to_eat != -1)
		philo->n_meals++;
	if (philo->data->n_times_to_eat > 0 \
		&& philo->n_meals >= philo->data->n_times_to_eat)
		set_n_f_phs(philo->data);
	philo->last_time_eat = get_current_time();
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	ft_sleep(t_philo *philo)
{
	print(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->n_philos == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		print(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die, philo);
		pthread_mutex_unlock(philo->r_fork);
		return (NULL);
	}
	if (philo->id % 2)
		ft_usleep(philo->data->time_to_eat, philo);
	while (get_stop_sim(philo) == 0)
	{
		take_fork(philo, philo->r_fork);
		take_fork(philo, philo->l_fork);
		ft_eat(philo);
		ft_sleep(philo);
		print(philo, "is thinking");
	}
	return (NULL);
}
