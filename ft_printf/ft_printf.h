/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:41:07 by aait-bab          #+#    #+#             */
/*   Updated: 2024/01/17 15:44:21 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putptr(uintptr_t ptr);
int	ft_putint(int nbr);
int	ft_putunsigned(unsigned int nbr);
int	ft_puthex(unsigned int nbr, char format);
int	ft_printf(const char *format, ...);
int	ft_print_type(va_list vlst, char format);
#endif