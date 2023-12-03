/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:03:05 by aait-bab          #+#    #+#             */
/*   Updated: 2023/10/04 12:03:07 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put(char c)
{
	write(1, &c, 1);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		put(*(str + i));
		i++;
	}
}

void	put_nbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		put('-');
		put_nbr(-1 * n);
	}
	else if (n > 9)
	{
		put_nbr(n / 10);
		put(n % 10 + 48);
	}
	else
		put(n + 48);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		put_str((par + i)->str);
		put('\n');
		put_nbr((par + i)->size);
		put('\n');
		put_str((par + i)->copy);
		put('\n');
		i++;
	}
}
