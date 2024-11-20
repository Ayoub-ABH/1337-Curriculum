/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:02:38 by aait-bab          #+#    #+#             */
/*   Updated: 2024/05/08 01:06:46 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min)
		/ (old_max - old_min) + new_min);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

double	ft_atod(const char *str)
{
	double	res;
	double	res2;
	double	sign;
	int		i;
	int		j;

	res = 0;
	res2 = 0;
	sign = 1;
	i = 0;
	j = 1;
	if (str[i] == '-' || str[i] == '+')
		sign = 44 - str[i++];
	while (str[i] && str[i] != '.')
		res = res * 10 + str[i++] - '0';
	if (str[i++] == '.')
		while (str[i])
			res2 = res2 + (str[i++] - '0') / pow(10, j++);
	if (((res + res2) * sign) > INT_MAX)
		return (INT_MAX);
	if (((res + res2) * sign) < INT_MIN)
		return (INT_MIN);
	return ((res + res2) * sign);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i] || (str[i] == '.' && !str[i + 1]))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (str[i++] == '.')
	{
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}
