/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:31:23 by aait-bab          #+#    #+#             */
/*   Updated: 2024/02/28 15:29:18 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	g_signal_received;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_signal_received = 1;
}

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
	valid = 0;
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

int	parse_send_msg(int pid, char **av, int i)
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
	while (av[2][i] != '\0')
	{
		if (send_char(pid, av[2][i]) == -1)
		{
			write(2, "invalid pid\n", 12);
			return (0);
		}
		i++;
	}
	if (send_char(pid, '\0') == -1)
	{
		write(2, "invalid pid\n", 12);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;
	int					i;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (parse_send_msg(pid, av, i) == 0)
			return (0);
	}
	else
		write(2, "invalid arguments\n", 19);
	if (g_signal_received)
		write(2, "message sent successfully\n", 26);
	return (0);
}
