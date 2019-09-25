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

void	move(int k, t_env *e)
{
	if (k == A || k == D)
		e->moveX += 0.025 / e->zoom * (k == A ? -1 : 1);
	if (k == W || k == S)
		e->moveY += 0.025 / e->zoom * (k == W ? -1 : 1);
}

void	zoom(int k, t_env *e)
{
	if (k == MINUS || k == PLUS)
		e->zoom += 0.1 * e->zoom * (k == MINUS ? -1 : 1);
}

void	alter_iteration(int k, t_env *e)
{
	if (k == O || k == P)
		e->maxIterations += 1 * (k == O ? -1 : 1);
}

int		key_press(int k, t_env *e)
{
	if (k == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	zoom(k, e);
	move(k, e);
	alter_iteration(k, e);
	mlx_destroy_image(e->mlx, e->pt_img);
	e->pt_img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	mandelbrot(e);
	//julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->pt_img, 0, 0);
	return (0);
}
