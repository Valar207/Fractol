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

#include "../includes/struct.h"
#include "../includes/keyboard_code.h"
#include <math.h>

void	mandelbrot(t_env *e)
{
	e->y = 0;
	while(e->y < HEIGHT)
	{
		e->x = 0;
		while(e->x < WIDTH)
		{
			e->pr = 1.5 * (e->x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->moveX;
    		e->pi = (e->y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->moveY;
			e->newRe = 0;
			e->newIm = 0;
			e->i = 0;
			while(e->i < e->maxIterations && (e->newRe * e->newRe + e->newIm * e->newIm) < 4)
			{
				e->oldRe = e->newRe;
				e->oldIm = e->newIm;
				e->newRe = e->oldRe * e->oldRe - e->oldIm * e->oldIm + e->pr;
				e->newIm = 2 * e->oldRe * e->oldIm + e->pi;
				e->i++;
				if (e->i == e->maxIterations)
					e->color = 0x56000000;
				else
					e->color = 0x3357FF00 * (e->i);
			}
			ft_fill_pix(e, e->x, e->y);
			e->x++;
		}
		e->y++;
	}
}