/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:41:27 by aait-bab          #+#    #+#             */
/*   Updated: 2024/01/17 16:07:14 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type(va_list vlst, char format)
{
	int	char_counter;

	char_counter = 0;
	if (format != 0)
	{
		if (format == 'c')
			char_counter += ft_putchar(va_arg(vlst, int));
		else if (format == 's')
			char_counter += ft_putstr(va_arg(vlst, char *));
		else if (format == 'p')
			char_counter += ft_putptr(va_arg(vlst, uintptr_t));
		else if (format == 'd' || format == 'i')
			char_counter += ft_putint(va_arg(vlst, int));
		else if (format == 'u')
			char_counter += ft_putunsigned(va_arg(vlst, unsigned int));
		else if (format == 'x' || format == 'X')
			char_counter += ft_puthex(va_arg(vlst, unsigned int), format);
		else if (format == '%')
			char_counter += ft_putchar('%');
		else
			char_counter += ft_putchar(format);
	}
	return (char_counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_counter;

	if (write(1, "", 0) < 0)
		return (-1);
	char_counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			char_counter += ft_print_type(args, *(++format));
		else
			char_counter += ft_putchar(*format);
		if (!*format)
			break ;
		format++;
	}
	va_end(args);
	return (char_counter);
}
