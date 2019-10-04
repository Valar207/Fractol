/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:38:29 by vrossi            #+#    #+#             */
/*   Updated: 2019/10/02 13:19:05 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../minilibx/mlx.h"
#include "libft/libft.h"

void	init_var(t_env *e)
{
	int		bpp;
	int		s_l;
	int		endian;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W, H, "FRACTOL");
	e->pt_img = mlx_new_image(e->mlx, W, H);
	e->my_img = mlx_get_data_addr(e->pt_img, &(bpp), &(s_l), &(endian));
	e->zoom = 0.6;
	e->mx = -0.5;
	e->my = 0;
	e->maxit = 40;
	e->click = 0;
	e->chgcol = 1;
	e->sw = 1;
	e->cr = 0.285;
	e->ci = 0.01;
}
