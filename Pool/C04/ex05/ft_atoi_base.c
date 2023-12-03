/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:41:49 by aait-bab          #+#    #+#             */
/*   Updated: 2023/09/25 18:39:43 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int	get_pos_n(char *str, int *i)
{
	int	sign;
	int	s;

	sign = -1;
	s = 0;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		*i = *i + 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			s++;
		*i = *i + 1;
	}
	if (s % 2 == 0)
		sign *= -1;
	return (sign);
}

int	in_base(char c, char *base, int *nb)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			*nb = i;
			return (1);
		}
		else
		{
			i++;
		}
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	nb;
	int	len;

	nb = 0;
	result = 0;
	i = 0;
	len = ft_len(base);
	if (is_base(base) == 0)
		return (0);
	sign = get_pos_n(str, &i);
	while (str[i])
	{
		if (in_base(str[i], base, &nb))
			result = (result * len) + nb;
		else 
			return (result * sign); 
		i++;
	}
	if (str[i] == '\0')
		return (result * sign);
	return (0);
}
