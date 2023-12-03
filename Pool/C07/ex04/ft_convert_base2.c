/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:46:38 by aait-bab          #+#    #+#             */
/*   Updated: 2023/10/02 19:53:30 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

int		ft_atoi_base(char *str, char *base);
int		str_ln(char *str);
bool	verif(char *str);

void	fill(long *nb, char *base_to, char *result, long x)
{
	int	i;

	if (*nb < 0)
	{
		*nb = -(*nb);
		i = x;
		result[x + 1] = '\0';
		while (i > 0)
		{
			result[i--] = base_to[*nb % str_ln(base_to)];
			*nb = *nb / str_ln(base_to);
		}
		result[i] = '-';
	}
	else
	{
		i = x - 1;
		result[x] = '\0';
		while (i >= 0)
		{
			result[i--] = base_to[*nb % str_ln(base_to)];
			*nb = *nb / str_ln(base_to);
		}
	}
}

int	count_digits(char *base_to, unsigned int t)
{
	int	x;

	x = 1;
	while (t / str_ln(base_to))
	{
		t /= str_ln(base_to);
		x++;
	}
	return (x);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	char	*result;
	long	x;

	if (str_ln(base_to) < 2 || str_ln(base_from) < 2
		|| !verif(base_from) || !verif(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	x = nb;
	if (nb < 0)
		x = -nb;
	x = count_digits(base_to, x);
	result = (char *)malloc((x + 2) * sizeof(char));
	fill(&nb, base_to, result, x); 
	return (result);
}
