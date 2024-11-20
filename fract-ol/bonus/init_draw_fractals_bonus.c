/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw_fractals_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 04:19:11 by aait-bab          #+#    #+#             */
/*   Updated: 2024/05/08 01:09:57 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	malloc_error(t_fractal *fractal)
{
	if (WINDOW_WIDTH < 0 || WINDOW_HEIGHT < 0)
		ft_putstr_fd("invalid window size\n", 2);
	else
		ft_putstr_fd("malloc error\n", 2);
	free(fractal);
	exit(1);
}

int	check_w_h(t_fractal *fractal)
{
	if (fractal->width < 0 || fractal->height < 0)
		return (0);
	return (1);
}

void	init_fractal(t_fractal *fractal, char *name)
{
	fractal->name = name;
	fractal->width = WINDOW_WIDTH;
	fractal->height = WINDOW_HEIGHT;
	fractal->mlx = mlx_init();
	if (!fractal->mlx || !check_w_h(fractal))
		malloc_error(fractal);
	fractal->window = mlx_new_window(fractal->mlx,
			fractal->width, fractal->height, fractal->name);
	if (!fractal->window)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		free(fractal->mlx);
		malloc_error(fractal);
	}
	fractal->image = mlx_new_image(fractal->mlx,
			fractal->width, fractal->height);
	if (!fractal->image)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		mlx_destroy_image(fractal->mlx, fractal->image);
		free(fractal->mlx);
		malloc_error(fractal);
	}
	fractal->addr = (int *)mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
}

void	init_draw_mandelbrot(t_fractal *fractal)
{
	init_fractal(fractal, fractal->name);
	fractal->zoom = 1;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->max_iter = 100;
	fractal->color = 0x000CF7EA;
	draw_mandelbrot(fractal);
}

void	init_draw_julia(t_fractal *fractal, double c_re, double c_im)
{
	init_fractal(fractal, fractal->name);
	fractal->zoom = 1;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->max_iter = 100;
	fractal->color = 0x000CF7EA;
	fractal->c_re = c_re;
	fractal->c_im = c_im;
	draw_julia(fractal);
}
