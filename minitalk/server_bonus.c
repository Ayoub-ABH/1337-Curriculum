/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:51 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/06 21:58:14 by aait-bab         ###   ########.fr       */
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

void	print_message(int c)
{
	static int	tab[4];
	static int	i;

	if ((c & 0x80) == 0x00) 
		write(1, &c, 1);
	else if ((c & 0xF8) != 0xF0)
	{
		tab[i++] = c;
		if (i == 4)
		{
			i = 0;
			while (i < 4)
				write(1, &tab[i++], 1);
			i = 0;
		}
	}
	else
	{
		tab[0] = c;
		i = 1;
	}
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
		if (character == '\0')
			kill(si->si_pid, SIGUSR1);
		print_message(character);
		nb_bits = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = sig_handle;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	write(1, "The server is up and running. It's PID is: ", 43);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		usleep(100);
	return (0);
}
