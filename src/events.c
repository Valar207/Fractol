/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/10/02 13:00:45 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
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
	mlx_string_put(e->mlx, e->win, 37, (H - 153), 0xC0C0C0, "Fract Explorer");
	mlx_string_put(e->mlx, e->win, 37, (H - 125), 0xC0C0C0, "1 = Mandelbrot");
	mlx_string_put(e->mlx, e->win, 37, (H - 105), 0xC0C0C0, "2 = Julia");
	mlx_string_put(e->mlx, e->win, 37, (H - 85), 0xC0C0C0,\
			"3 = Celtic_Mandelbrot");
	mlx_string_put(e->mlx, e->win, 37, (H - 65), 0xC0C0C0, "4 = Burning_Ship");
	mlx_string_put(e->mlx, e->win, 37, (H - 45), 0xC0C0C0, "5 = Mandelbar");
	mlx_string_put(e->mlx, e->win, 800, (H - 555), 0xC0C0C0, e->arg);
	mlx_string_put(e->mlx, e->win, 800, (H - 55), 0xC0C0C0, "nb iterations :");
	mlx_string_put(e->mlx, e->win, 960, (H - 55), 0xC0C0C0, ft_itoa(e->maxit));
}

void	move_zoom_iteration(int k, t_env *e)
{
	if (k == A || k == D)
		e->mx += 0.025 / e->zoom * (k == A ? -1 : 1);
	if (k == KW || k == S)
		e->my += 0.025 / e->zoom * (k == KW ? -1 : 1);
	if (k == MINUS || k == PLUS)
		e->zoom += 0.1 * e->zoom * (k == MINUS ? -1 : 1);
	if (k == O || k == P)
		e->maxit += 1 * (k == O ? -1 : 1);
	if (e->maxit < 5)
		e->maxit = 5;
}

void	key_press_bis(int k, t_env *e)
{
	change_fract(k, e);
	move_zoom_iteration(k, e);
	mlx_destroy_image(e->mlx, e->pt_img);
	e->pt_img = mlx_new_image(e->mlx, W, H);
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
		e->mx = (ft_strncmp(e->arg, "julia", 5) == 0 ? 0 : -0.5);
		e->my = 0;
		e->maxit = 40;
	}
	key_press_bis(k, e);
	return (0);
}
