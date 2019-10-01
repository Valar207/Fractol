/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/18 11:40:46 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include "../includes/struct.h"
#include "../includes/keyboard_code.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
	{
		write(2, "usage: ./fractol [mandelbrot|julia...]\n", 39);
		exit(0);
	}
	init_var(&e);
	e.arg = av[1];
	if ((ft_strncmp(av[1], "mandelbrot", 10) == 0))
	{
		e.moveX = -0.5;
		mandelbrot(&e);
	}
	if ((ft_strncmp(av[1], "celtic_mandelbrot", 10) == 0))
	{
		e.moveX = -0.5;
		celtic_mandelbrot(&e);
	}
	if ((ft_strncmp(av[1], "burning_ship", 10) == 0))
	{
		e.moveX = -0.5;
		burning_ship(&e);
	}
	if ((ft_strncmp(av[1], "julia", 5) == 0))
	{
		e.cr = 0;
		e.ci = 0;
		julia(&e);
	}
	mlx_put_image_to_window(e.mlx, e.win, e.pt_img, 0, 0);
	mlx_hook(e.win, 2, 0, key_press, &e);
	mlx_hook(e.win, 6, 0, mouse_move, &e);
	mlx_hook(e.win, 5, 0, mouse_release, &e);
	mlx_hook(e.win, 4, 0, mouse_press, &e);
	mlx_loop(e.mlx);
	return (0);
}
