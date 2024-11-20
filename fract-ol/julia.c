/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:59:47 by aait-bab          #+#    #+#             */
/*   Updated: 2024/05/07 15:44:27 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_pixel_julia(t_fractal *fractal, int x, int y)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	z_re = map(x, -2, 2, fractal->width) * fractal->zoom + fractal->move_x;
	z_im = map(y, 2, -2, fractal->height) * fractal->zoom + fractal->move_y;
	i = 0;
	while (z_re * z_re + z_im * z_im < 4 && i < fractal->max_iter)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + fractal->c_re;
		z_im = 2 * z_im * tmp + fractal->c_im;
		i++;
	}
	if (i == fractal->max_iter)
		fractal->addr[y * fractal->width + x] = 0x00000000;
	else
		fractal->addr[y * fractal->width + x] = i * fractal->color;
}

void	draw_julia(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			calculate_pixel_julia(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->window, fractal->image, 0, 0);
}
