/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:54:16 by aait-bab          #+#    #+#             */
/*   Updated: 2024/05/06 04:09:15 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calculate_pixel_mandelbrot(t_fractal *fractal, int x, int y)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	z_re = 0;
	z_im = 0;
	i = 0;
	fractal->c_re = map(x, -2, 2, fractal->width)
		* fractal->zoom + fractal->move_x;
	fractal->c_im = map(y, 2, -2, fractal->height)
		* fractal->zoom + fractal->move_y;
	while (z_re * z_re + z_im * z_im < 4 && i < fractal->max_iter)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + fractal->c_re;
		z_im = 2 * z_im * tmp + fractal->c_im;
		i++;
	}
	if (i == fractal->max_iter)
		fractal->addr[y * fractal->width + x] = 0x000000;
	else
		fractal->addr[y * fractal->width + x] = i * fractal->color;
}

void	draw_mandelbrot(t_fractal *fractal)
{
	int		x;
	int		y;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			calculate_pixel_mandelbrot(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->window, fractal->image, 0, 0);
}
