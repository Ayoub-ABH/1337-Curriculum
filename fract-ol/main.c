/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:43:05 by aait-bab          #+#    #+#             */
/*   Updated: 2024/05/10 15:50:43 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

void	execute_fractal(t_fractal *fractal, char **av, int ac)
{
	if (!ft_strcmp(fractal->name, "mandelbrot") && ac == 2)
		init_draw_mandelbrot(fractal);
	else if (!ft_strcmp(fractal->name, "julia") && ac == 4
		&& ft_isnum(av[2]) && ft_isnum(av[3]))
	{
		if (ft_atod(av[2]) == INT_MAX || ft_atod(av[3]) == INT_MAX
			|| ft_atod(av[2]) == INT_MIN || ft_atod(av[3]) == INT_MIN)
		{
			ft_putstr_fd("invalid number\n", 2);
			free(fractal);
			exit(1);
		}
		init_draw_julia(fractal, ft_atod(av[2]), ft_atod(av[3]));
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, 2);
		free(fractal);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_fractal	*fractal;

	if (ac != 2 && ac != 4)
	{
		ft_putstr_fd(ERROR_MSG, 2);
		return (0);
	}
	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
	{
		ft_putstr_fd("malloc error\n", 2);
		return (0);
	}
	fractal->name = ft_tolower(av[1]);
	execute_fractal(fractal, av, ac);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0, close_window, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
