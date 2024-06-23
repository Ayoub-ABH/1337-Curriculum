/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:15:52 by aait-bab          #+#    #+#             */
/*   Updated: 2023/12/07 23:04:21 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthelper(uintptr_t nbr)
{
	char	*base;
	int		char_counter;

	base = "0123456789abcdef";
	char_counter = 0;
	if (nbr >= 16)
	{
		char_counter += ft_puthelper(nbr / 16);
		char_counter += ft_puthelper(nbr % 16);
	}
	else
	{
		char_counter += ft_putchar(base[nbr]);
	}
	return (char_counter);
}

int	ft_putptr(uintptr_t nbr)
{
	int	len_char;

	len_char = write(1, "0x", 2) + ft_puthelper(nbr);
	return (len_char);
}
