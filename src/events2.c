/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/10/02 13:09:00 by vrossi           ###   ########.fr       */
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

void	change_fract_bis(int k, t_env *e)
{
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
		e->mx = 0;
		mandelbar(e);
		e->arg = "mandelbar";
	}
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
		e->mx = 0;
		e->cr = 0.285;
		e->ci = 0.01;
		julia(e);
		e->arg = "julia";
	}
	change_fract_bis(k, e);
}
