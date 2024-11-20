/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:44:03 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/18 15:37:23 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				n_philos;
	int				n_times_to_eat;
	int				stop_sim;
	int				n_full_philos;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	t_philo			*philos;
	pthread_t		monitor_t;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	stop_sim_lock;
	pthread_mutex_t	meals_lock;
	pthread_mutex_t	time_lock;
}	t_data;

struct s_philo
{
	int				id;
	int				n_meals;
	long			last_time_eat;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_data			*data;
};

int		is_numbers(char **av);
int		check_numbers(char **av);
long	ft_atoi(char *str);

int		init_data(t_data *data, char **av);

long	get_current_time(void);
int		simulate(t_data *data);
void	*philo_routine(void *arg);
void	*monitoring(void *arg);
int		ft_usleep(long time, t_philo *philo);

int		get_stop_sim(t_philo *philo);
long	get_last_time(t_philo philo);
int		get_n_f_phs(t_data *data);
void	set_n_f_phs(t_data *data);

void	set_last_time(t_philo philo);
void	set_stop_sim(t_philo *philo);

void	clean(t_data *data);
void	clean_forks(int n_philos, pthread_mutex_t *forks);
void	clean_locks(t_data *data, int n_locks);

#endif