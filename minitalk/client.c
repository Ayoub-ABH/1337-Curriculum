/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:00:37 by aait-bab          #+#    #+#             */
/*   Updated: 2024/02/28 15:23:47 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int			i;
	int			s;
	long int	r;
	long int	x;

	i = 0;
	r = 0;
	s = 1;
	x = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		s = 44 - str[i++];
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = r * 10 + str[i++] - '0';
		if (r > x && s == 1)
			return (-1);
		else if (r > x && s == -1)
			return (0);
		r = x;
	}
	if (str[i] != '\0')
		return (0);
	return (r * s);
}

int	send_char(int pid, char c)
{
	int	bit;
	int	valid;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			valid = kill(pid, SIGUSR1);
		else
			valid = kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
	return (valid);
}

int	parse(int pid, char **av, int i)
{
	if (pid <= 0)
	{
		write(2, "invalid pid\n", 12);
		return (0);
	}
	if (!av[2][i])
	{
		write(2, "invalid message\n", 16);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (parse(pid, av, i) == 0)
			return (0);
		while (av[2][i] != '\0')
		{
			if (send_char(pid, av[2][i]) == -1)
			{
				write(2, "invalid pid\n", 12);
				return (0);
			}
			i++;
		}
	}
	else
		write(2, "invalid arguments\n", 19);
	return (0);
}
