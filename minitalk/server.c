/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:58:32 by aait-bab          #+#    #+#             */
/*   Updated: 2024/02/27 21:34:15 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putnbr(long nbr)
{
	char	temp;

	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	temp = nbr % 10 + '0';
	write(1, &temp, 1);
}

void	sig_handle(int signal, siginfo_t *si, void *unused)
{
	static int	character;
	static int	nb_bits;
	static int	prev_pid;

	(void)unused;
	if (prev_pid != si->si_pid)
	{
		character = 0;
		nb_bits = 0;
		prev_pid = si->si_pid;
	}
	if (signal == SIGUSR1)
		character += 1 << nb_bits;
	else
		character += 0 << nb_bits;
	nb_bits++;
	if (nb_bits == 8)
	{
		write(1, &character, 1);
		nb_bits = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = sig_handle;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	write(1, "The server is up and running. It's PID is: ", 43);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		usleep(100);
	return (0);
}
