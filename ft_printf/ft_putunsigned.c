/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:06:14 by aait-bab          #+#    #+#             */
/*   Updated: 2023/12/07 23:10:42 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthelper(unsigned int nbr)
{
	char	*base;
	int		char_counter;

	base = "0123456789";
	char_counter = 0;
	if (nbr >= 10)
	{
		char_counter += ft_puthelper(nbr / 10);
		char_counter += ft_puthelper(nbr % 10);
	}
	else
	{
		char_counter += ft_putchar(base[nbr]);
	}
	return (char_counter);
}

int	ft_putunsigned(unsigned int nbr)
{
	int	len_char;

	len_char = ft_puthelper(nbr);
	return (len_char);
}
