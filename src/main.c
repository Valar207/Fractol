/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/10/02 15:43:15 by vrossi           ###   ########.fr       */
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
#include <math.h>

void	choose_fract(t_env *e, char **av)
{
	if ((ft_strncmp(av[1], "mandelbrot", 10) == 0))
	{
		e->mx = -0.5;
		mandelbrot(e);
	}
	if ((ft_strncmp(av[1], "celtic_mandelbrot", 10) == 0))
	{
		e->mx = -0.5;
		celtic_mandelbrot(e);
	}
	if ((ft_strncmp(av[1], "mandelbar", 10) == 0))
	{
		e->mx = 0;
		mandelbar(e);
	}
	if ((ft_strncmp(av[1], "burning_ship", 10) == 0))
	{
		e->mx = -0.5;
		burning_ship(e);
	}
	if ((ft_strncmp(av[1], "julia", 5) == 0))
	{
		e->mx = 0;
		julia(e);
	}
}

void	mlx_cmd(t_env *e)
{
	mlx_hook(e->win, 2, 0, key_press, e);
	mlx_hook(e->win, 6, 0, mouse_move, e);
	mlx_hook(e->win, 5, 0, mouse_release, e);
	mlx_hook(e->win, 4, 0, mouse_press, e);
	mlx_loop(e->mlx);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
	{
		write(2, "usage: ./fractol [mandelbrot|julia|burning_ship...]\n", 53);
		exit(0);
	}
	if (ft_strncmp(av[1], "burning_ship", 12) == 0 ||\
	ft_strncmp(av[1], "mandelbrot", 10) == 0 || ft_strncmp(av[1],\
	"celtic_mandelbrot", 17) == 0 || ft_strncmp(av[1], "julia", 5) == 0 ||\
	ft_strncmp(av[1], "mandelbar", 9) == 0)
	{
		init_var(&e);
		e.arg = av[1];
		choose_fract(&e, av);
		mlx_put_image_to_window(e.mlx, e.win, e.pt_img, 0, 0);
		user_interface_texts(&e);
		mlx_cmd(&e);
	}
	else
	{
		write(2, "usage: ./fractol [mandelbrot|julia|burning_ship...]\n", 53);
		exit(0);
	}
	return (0);
}
