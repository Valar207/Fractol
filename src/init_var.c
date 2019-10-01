/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:38:29 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/18 10:32:45 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "libft/libft.h"

void	init_var(t_env *e)
{
	int		bpp;
	int		s_l;
	int		endian;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "FRACTOL");
	e->pt_img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->my_img = mlx_get_data_addr(e->pt_img, &(bpp), &(s_l), &(endian));
	e->zoom = 0.6;
	e->moveX = 0;
	e->moveY = 0;
	e->maxIterations = 40;
	e->click = 0;
	e->chgcol = 1;
	e->sw = 1;
}