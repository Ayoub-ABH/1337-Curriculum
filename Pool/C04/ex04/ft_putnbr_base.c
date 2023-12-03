/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:00:52 by aait-bab          #+#    #+#             */
/*   Updated: 2023/09/25 15:40:44 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_char(int c)
{
	write(1, &c, 1);
}

int	is_base(char *base)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (base[i] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] <= 32 || base[i] == 127 || base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	return (1);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		len;
	long	nb;

	i = 0;
	nb = nbr;
	len = ft_len(base);
	if (is_base(base) == 0)
		return ;
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = nb * (-1);
	}
	if (nb >= len)
	{
		ft_putnbr_base(nb / len, base);
		ft_putnbr_base(nb % len, base);
	}
	else
	{
		put_char(base[nb]);
	}
}
