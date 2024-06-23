/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:20:59 by aait-bab          #+#    #+#             */
/*   Updated: 2023/12/07 23:09:02 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthelper(unsigned int nbr, char format)
{
	char	*lowerbase;
	char	*upperbase;
	int		char_counter;

	lowerbase = "0123456789abcdef";
	upperbase = "0123456789ABCDEF";
	char_counter = 0;
	if (nbr >= 16)
	{
		char_counter += ft_puthelper(nbr / 16, format);
		char_counter += ft_puthelper(nbr % 16, format);
	}
	else
	{
		if (format == 'X')
			char_counter += ft_putchar(upperbase[nbr]);
		else
			char_counter += ft_putchar(lowerbase[nbr]);
	}
	return (char_counter);
}

int	ft_puthex(unsigned int nbr, char format)
{
	int	len_char;

	len_char = ft_puthelper(nbr, format);
	return (len_char);
}
