/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/18 11:28:36 by vrossi           ###   ########.fr       */
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

void	move_zoom_iteration(int k, t_env *e)
{
	if (k == A || k == D)
		e->moveX += 0.025 / e->zoom * (k == A ? -1 : 1);
	if (k == W || k == S)
		e->moveY += 0.025 / e->zoom * (k == W ? -1 : 1);
	if (k == MINUS || k == PLUS)
		e->zoom += 0.1 * e->zoom * (k == MINUS ? -1 : 1);
	if (k == O || k == P)
		e->maxIterations += 1 * (k == O ? -1 : 1);
}

void	change_fract(int k, t_env *e)
{
	if (k == NUM_1)
	{
		mandelbrot(e);
		e->arg = "mandelbrot";
	}
	if (k == NUM_2)
	{
		julia(e);
		e->arg = "julia";
	}
	if (k == NUM_3)
	{
		celtic_mandelbrot(e);
		e->arg = "celtic_mandelbrot";
	}
	if (k == NUM_4)
	{
		burning_ship(e);
		e->arg = "burning_ship";
	}
}

int		key_press(int k, t_env *e)
{
	if (k == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	if (k == R)
	{
		e->zoom = 1;
		e->moveX = (ft_strncmp(e->arg, "julia", 5) == 0 ? 0 : -0.5);
		e->moveY = 0;
		e->maxIterations = 20;
	}
	change_fract(k, e);
	move_zoom_iteration(k, e);
	mlx_destroy_image(e->mlx, e->pt_img);
	e->pt_img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if ((ft_strncmp(e->arg, "mandelbrot", 10) == 0))
		mandelbrot(e);
	if ((ft_strncmp(e->arg, "celtic_mandelbrot", 10) == 0))
		celtic_mandelbrot(e);
	if ((ft_strncmp(e->arg, "burning_ship", 10) == 0))
		burning_ship(e);
	if ((ft_strncmp(e->arg, "julia", 5) == 0))
		julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->pt_img, 0, 0);
	return (0);
}
