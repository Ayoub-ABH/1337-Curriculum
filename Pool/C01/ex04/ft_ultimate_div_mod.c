/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:31:06 by aait-bab          #+#    #+#             */
/*   Updated: 2023/09/14 22:38:29 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div ;
	int	mod ;

	div = 0;
	mod = 0;
	if (*b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
	}
	*a = div;
	*b = mod;
}
