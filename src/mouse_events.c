/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/10/02 13:12:05 by vrossi           ###   ########.fr       */
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

int		mouse_move(int x, int y, t_env *e)
{
	if ((ft_strncmp(e->arg, "julia", 5) != 0))
		return (0);
	if (e->click == 0)
	{
		e->ci = (double)y * 2 / H - 1;
		e->cr = (double)x * 2 / W - 1;
	}
	mlx_destroy_image(e->mlx, e->pt_img);
	e->pt_img = mlx_new_image(e->mlx, W, H);
	if ((ft_strncmp(e->arg, "julia", 5) == 0))
		julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->pt_img, 0, 0);
	user_interface_texts(e);
	return (0);
}

int		mouse_release(int k, int x, int y, t_env *e)
{
	if (k == 1)
		e->click = (e->click == 1 ? 0 : 1);
	return (0);
}

void	zoom_mouse(t_coord *c, t_env *e)
{
	double	move;

	move = 0.1 / e->zoom;
	if (W / 2 < c->x)
		e->mx += move;
	else if (W / 2 > c->x)
		e->mx -= move;
	if (H / 2 < c->y)
		e->my += move;
	else if (H / 2 > c->y)
		e->my -= move;
}

int		mouse_press(int k, int x, int y, t_env *e)
{
	double	scale;
	t_coord c;

	c.x = x;
	c.y = y;
	if (k == 5 || k == 4)
	{
		zoom_mouse(&c, e);
		e->zoom += 0.1 * e->zoom * (k == 5 ? -1 : 1);
	}
	mlx_destroy_image(e->mlx, e->pt_img);
	e->pt_img = mlx_new_image(e->mlx, W, H);
	if ((ft_strncmp(e->arg, "mandelbrot", 10) == 0))
		mandelbrot(e);
	if ((ft_strncmp(e->arg, "celtic_mandelbrot", 10) == 0))
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
