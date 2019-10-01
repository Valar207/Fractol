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


void	user_interface_texts(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 41, 35, 0xC0C0C0, "Controls Keys");
	mlx_string_put(e->mlx, e->win, 37, 63, 0xC0C0C0, "Move = A W S D");
	mlx_string_put(e->mlx, e->win, 37, 83, 0xC0C0C0, "Iter = O and P");
	mlx_string_put(e->mlx, e->win, 37, 103, 0xC0C0C0, "Zoom = - and +");
	mlx_string_put(e->mlx, e->win, 37, 123, 0xC0C0C0, "Color RGB = C");
	mlx_string_put(e->mlx, e->win, 37, 143, 0xC0C0C0, "Reset = R");
	mlx_string_put(e->mlx, e->win, 41, 248, 0xC0C0C0, "Controls Mouse");
	mlx_string_put(e->mlx, e->win, 37, 276, 0xC0C0C0, "Zoom = SCROLL");
	mlx_string_put(e->mlx, e->win, 37, (HEIGHT - 153), 0xC0C0C0, "Fract Explorer");
	mlx_string_put(e->mlx, e->win, 37, (HEIGHT - 125), 0xC0C0C0, "1 = Mandelbrot");
	mlx_string_put(e->mlx, e->win, 37, (HEIGHT - 105), 0xC0C0C0, "2 = Julia");
	mlx_string_put(e->mlx, e->win, 37, (HEIGHT - 85), 0xC0C0C0, "3 = Celtic_Mandelbrot");
	mlx_string_put(e->mlx, e->win, 37, (HEIGHT - 65), 0xC0C0C0, "4 = Burning_Ship");
	mlx_string_put(e->mlx, e->win, 37, (HEIGHT - 45), 0xC0C0C0, "5 = Mandelbar");
	mlx_string_put(e->mlx, e->win, 800, (HEIGHT - 555), 0xC0C0C0, e->arg);
	mlx_string_put(e->mlx, e->win, 800, (HEIGHT - 55), 0xC0C0C0, "nb iterations :");
	mlx_string_put(e->mlx, e->win, 960, (HEIGHT - 55), 0xC0C0C0, ft_itoa(e->maxIterations));
}

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
	if (e->maxIterations < 5)
		e->maxIterations = 5;
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
		e->moveX = 0;
		e->cr = 0.285;
		e->ci = 0.01;
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
	if (k == NUM_5)
	{
		e->moveX = 0;
		mandelbar(e);
		e->arg = "mandelbar";
	}
}

int		key_press(int k, t_env *e)
{
	if (k == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	if (k == C)
	{
		e->sw = 1;
		e->chgcol += 1;	
	}
	if (k == V)
		e->sw = 2;
	if (k == R)
	{
		e->zoom = 0.6;
		e->moveX = (ft_strncmp(e->arg, "julia", 5) == 0 ? 0 : -0.5);
		e->moveY = 0;
		e->maxIterations = 40;
	}
	change_fract(k, e);
	move_zoom_iteration(k, e);
	mlx_destroy_image(e->mlx, e->pt_img);
	e->pt_img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if ((ft_strncmp(e->arg, "mandelbrot", 10) == 0))
		mandelbrot(e);
	if ((ft_strncmp(e->arg, "celtic_mandelbrot", 17) == 0))
		celtic_mandelbrot(e);
	if ((ft_strncmp(e->arg, "burning_ship", 10) == 0))
		burning_ship(e);
	if ((ft_strncmp(e->arg, "julia", 5) == 0))
		julia(e);
	if ((ft_strncmp(e->arg, "mandelbar", 9) == 0))
		mandelbar(e);
	mlx_put_image_to_window(e->mlx, e->win, e->pt_img, 0, 0);
	user_interface_texts(e);
	return (0);
}
