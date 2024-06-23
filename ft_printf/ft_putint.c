/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:52:30 by aait-bab          #+#    #+#             */
/*   Updated: 2023/12/07 23:01:46 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthelper(int nbr)
{
	char	*base;
	long	nb;
	int		char_counter;

	base = "0123456789";
	nb = nbr;
	char_counter = 0;
	if (nb < 0)
	{
		char_counter += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		char_counter += ft_puthelper(nb / 10);
		char_counter += ft_puthelper(nb % 10);
	}
	else
	{
		char_counter += ft_putchar(base[nb]);
	}
	return (char_counter);
}

int	ft_putint(int nbr)
{
	int	len_char;

	len_char = ft_puthelper(nbr);
	return (len_char);
}
