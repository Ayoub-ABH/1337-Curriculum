/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:50:43 by aait-bab          #+#    #+#             */
/*   Updated: 2024/05/10 16:19:37 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		free(fractal);
		exit(1);
	}
	if (keycode == 123)
		fractal->move_x += 0.1 * fractal->zoom;
	if (keycode == 124)
		fractal->move_x -= 0.1 * fractal->zoom;
	if (keycode == 125)
		fractal->move_y += 0.1 * fractal->zoom;
	if (keycode == 126)
		fractal->move_y -= 0.1 * fractal->zoom;
	if (keycode == 257)
		fractal->color += 0x00000011;
	if (!ft_strcmp(fractal->name, "julia"))
		draw_julia(fractal);
	else if (!ft_strcmp(fractal->name, "burning_ship"))
		draw_burning_ship(fractal);
	else
		draw_mandelbrot(fractal);
	return (0);
}

int	close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal);
	exit (1);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractal->zoom *= 1.1;
		if (ft_strcmp(fractal->name, "julia") == 0)
			draw_julia(fractal);
		else if (ft_strcmp(fractal->name, "burning_ship") == 0)
			draw_burning_ship(fractal);
		else
			draw_mandelbrot(fractal);
	}
	else if (button == 5)
	{
		fractal->zoom *= 0.8;
		if (ft_strcmp(fractal->name, "julia") == 0)
			draw_julia(fractal);
		else if (ft_strcmp(fractal->name, "burning_ship") == 0)
			draw_burning_ship(fractal);
		else
			draw_mandelbrot(fractal);
	}
	return (0);
}
