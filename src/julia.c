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

void	julia(t_env *e)
{
	e->y = 0;

	while(e->y < HEIGHT)
	{
		e->x = 0;
		while(e->x < WIDTH)
		{
			e->newRe = 1.5 * (e->x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->moveX;
			e->newIm = (e->y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->moveY;
			e->i = 0;
			while(e->i < e->maxIterations && (e->newRe * e->newRe + e->newIm * e->newIm) < 4)
			{
				e->oldRe = e->newRe;
				e->oldIm = e->newIm;
				e->newRe = e->oldRe * e->oldRe - e->oldIm * e->oldIm + e->cr;
				e->newIm = 2 * e->oldRe * e->oldIm + e->ci;
				e->i++;
				color(e);	
			}
			ft_fill_pix(e, e->x, e->y);
			e->x++;
		}
		e->y++;
	}
}