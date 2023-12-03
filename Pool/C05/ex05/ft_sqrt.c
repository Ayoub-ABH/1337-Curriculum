/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:15:04 by aait-bab          #+#    #+#             */
/*   Updated: 2023/09/26 18:19:46 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	high;
	long	low;
	long	cast;
	long	m;

	cast = nb;
	if (cast <= 0)
		return (0);
	if (cast == 1)
		return (1);
	low = 1;
	high = nb;
	while (low <= high)
	{
		m = (low + high) / 2;
		if (m * m > nb)
			high = m - 1;
		else
			low = m + 1;
	}
	if (high * high == cast)
		return ((int)high);
	return (0);
}
// int newtonSqrt(int nb) 
// {
//     if (nb <= 0)
//         return 0;
//     // Initial guess for the square root (can be any positive integer)
//     int x0 = nb;
//     // Perform iterations using Newton's method
//     while (1) {
//         int x1 = (x0 + nb / x0) / 2;
//         // Check if the guess has converged
//         if (x1 >= x0) {
//             return x0;
//         }
//         x0 = x1;
//     }
// }
