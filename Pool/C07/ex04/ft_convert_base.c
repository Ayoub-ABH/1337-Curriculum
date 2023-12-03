/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:45:28 by aait-bab          #+#    #+#             */
/*   Updated: 2023/10/02 19:53:27 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

int	str_ln(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	verif(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		if (str[i] == '-' || str[i] == '+' || str[i] == ' ')
			return (false);
		while (str[j])
		{
			if (str[i] == str[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	get_pos(char *base, char value)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	powr(int x, int y)
{
	int	n;

	n = x;
	if (y == 0)
		return (1);
	else
	{
		while (y > 1)
		{
			x *= n;
			y--;
		}
		return (x);
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	neg;
	int	j;
	int	k;

	i = 0;
	result = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	j = i;
	while (get_pos(base, str[j]) != -1)
		j++;
	k = j - i -1;
	while (i < j)
		result += powr(str_ln(base), k--) * get_pos(base, str[i++]);
	return (neg * result);
}
