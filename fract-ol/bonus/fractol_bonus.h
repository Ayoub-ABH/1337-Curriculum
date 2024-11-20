/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:18:22 by aait-bab          #+#    #+#             */
/*   Updated: 2024/05/08 01:10:31 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <limits.h> 
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include "mlx.h"

# define ERROR_MSG "Usage: \n\t./fractol_bonus mandelbrot\n\
	./fractol_bonus burning_ship\n\
	./fractol_bonus julia [c_real] [c_imaginary]\n"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800

typedef struct s_fractal
{
	char	*name;
	int		width;
	int		height;
	void	*mlx;
	void	*window;
	int		color;
	double	c_re;
	double	c_im;
	double	zoom;
	double	move_x;
	double	move_y;
	int		max_iter;
	void	*image;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fractal;

void	init_fractal(t_fractal *fractal, char *name);
void	init_draw_mandelbrot(t_fractal *fractal);
void	init_draw_julia(t_fractal *fractal, double c_re, double c_im);
void	init_draw_burning_ship(t_fractal *fractal);
void	draw_mandelbrot(t_fractal *fractal);
void	draw_burning_ship(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
int		key_hook(int keycode, t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
int		close_window(t_fractal *fractal);
double	map(double unscaled_num, double new_min,
			double new_max, double old_max);
int		ft_strcmp(const char *s1, const char *s2);
double	ft_atod(const char *str);
int		ft_isnum(char *str);
void	ft_putstr_fd(char *s, int fd);
#endif